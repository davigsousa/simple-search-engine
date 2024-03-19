#include "review.h"

Review::Review(std::string criticName, std::string content, std::string score) {
    this->criticName = criticName;
    this->content = content;
    this->score = score;
}

std::string Review::getCriticName() {
    return this->criticName;
}

std::string Review::getContent() {
    return this->content;
}

std::string Review::getScore() {
    return this->score;
}
