#include "csv_reader.h"
#include "logger.h"

CSVReader::CSVReader(std::string filename) {
    this->filename = filename;

    this->file.open(this->filename);
}

CSVReader::~CSVReader() {
    this->file.close();
}

Review CSVReader::parseLine(std::string line) {
    std::stringstream ss(line);
    std::string ignoreValue;
    std::string criticName;
    std::string content;
    std::string scoreString;

    std::getline(ss, ignoreValue, ',');
    std::getline(ss, criticName, ',');
    std::getline(ss, ignoreValue, ',');
    std::getline(ss, ignoreValue, ',');
    std::getline(ss, ignoreValue, ',');
    std::getline(ss, scoreString, ',');
    std::getline(ss, ignoreValue, ',');
    std::getline(ss, content, ',');

    double score = std::stod(scoreString);
    return Review(criticName, content, score);
}

bool CSVReader::isValidLine(std::string line) {
    std::stringstream ss(line);
    std::string value;

    // Check if critic_name is not empty
    std::getline(ss, value, ',');
    std::getline(ss, value, ',');
    if (value.size() == 0) {
        return false;
    }

    for (int i = 0; i < 4; i++) {
        std::getline(ss, value, ',');
    }

    // Check if score field can be converted to double
    try {
        std::stod(value);
    } catch (std::invalid_argument e) {
        return false;
    }

    // Check if review_content is not empty
    std::getline(ss, value, ',');
    std::getline(ss, value, ',');
    if (value.size() == 0) {
        return false;
    }


    return true;
}

std::vector<Review> CSVReader::getReviews() {
    std::vector<std::string> lines;
    std::string line;

    logMessage("Reading file...");

    // Ignoring header
    std::getline(this->file, line);

    while (std::getline(this->file, line)) {
        if (isValidLine(line)) {
            lines.push_back(line);
        }
    }

    logMessage("File read successfully!");
    logMessage("Parsing reviews...");

    std::vector<Review> reviews;
    for (auto line : lines) {
        auto review = parseLine(line);
        reviews.push_back(review);
    }

    logMessage("Reviews parsed successfully!");

    std::string message = "Number of valid reviews: " + std::to_string(reviews.size());
    logMessage(message);

    return reviews;
}
