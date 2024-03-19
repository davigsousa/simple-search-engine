#ifndef REVIEW_H
#define REVIEW_H

#include <string>

class Review {
    private:
        std::string criticName;
        std::string content;
        double score;

    public:
        Review(std::string criticName, std::string content, double score);
        std::string getCriticName();
        std::string getContent();
        double getScore();
};

#endif