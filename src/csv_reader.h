#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "review.h"

class CSVReader {
    private:
        std::string filename;
        std::ifstream file;

        bool isValidLine(std::string line);
        Review parseLine(std::string line);
    public:
        CSVReader(std::string filename);
        ~CSVReader();
        std::vector<Review> getReviews();
};

#endif