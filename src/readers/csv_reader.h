#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "entities/review.h"

/**
 * @class CSVReader
 * @brief A class to read data from a CSV file.
 *
 * CSVReader is a class that takes a filename as input
 * and provides a method to read the data from the file
 * and return a vector of Review objects.
 */
class CSVReader {
    private:
        std::string filename; ///< The name of the file to read from.
        std::ifstream file; ///< The file stream.

        /**
         * @brief Check if a line from the CSV file is valid as a Movie Review.
         * @param line The line to check.
         * @return true if the line is valid, false otherwise.
         */
        bool isValidLine(std::string line);

        /**
         * @brief Parse a line from the CSV file into a Review object.
         * @param line The line to parse.
         * @return The parsed Review object.
         */
        Review parseLine(std::string line);

    public:
        /**
         * @brief Construct a new CSVReader object.
         * @param filename The name of the file to read from.
         */
        CSVReader(std::string filename);

        /**
         * @brief Destroy the CSVReader object.
         */
        ~CSVReader();

        /**
         * @brief Get a vector of Review objects from the CSV file.
         * @return A vector of Review objects.
         */
        std::vector<Review> getReviews();
};

#endif