#ifndef REVIEW_H
#define REVIEW_H

#include <string>

/**
 * @brief The Review class represents a review given by a critic.
 * 
 * This class stores information about a review, including the critic's name, the content of the review, and the score given to the reviewed item.
 */
class Review {
    private:
        std::string criticName; /**< The name of the critic who wrote the review. */
        std::string content; /**< The content of the review. */
        std::string score; /**< The score given to the reviewed item. */

    public:
        /**
         * @brief Constructs a new Review object.
         * 
         * @param criticName The name of the critic who wrote the review.
         * @param content The content of the review.
         * @param score The score given to the reviewed item.
         */
        Review(std::string criticName, std::string content, std::string score);

        /**
         * @brief Gets the name of the critic who wrote the review.
         * 
         * @return The name of the critic.
         */
        std::string getCriticName();

        /**
         * @brief Gets the content of the review.
         * 
         * @return The content of the review.
         */
        std::string getContent();

        /**
         * @brief Gets the score given to the reviewed item.
         * 
         * @return The score of the review.
         */
        std::string getScore();
};

#endif