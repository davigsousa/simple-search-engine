#include <iostream>
#include "csv_reader.h"
using namespace std;

int main() {
  auto reader = new CSVReader("./data/reviews.csv");
  reader->getReviews();

  return 0;
}
