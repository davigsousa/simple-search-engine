#include <iostream>
#include "readers/csv_reader.h"
using namespace std;

int main() {
  auto reader = new CSVReader("./data/reviews.csv");
  auto reviews = reader->getReviews();

  for (auto review : reviews) {
    cout << review.getCriticName() << " - " << review.getContent() << " - " << review.getScore() << endl;
  }

  return 0;
}
