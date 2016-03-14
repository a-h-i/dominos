#include "board.hpp"
#include <algorithm>

Board::Board() {
  pile.reserve(28);
  for (int i = 0; i < 7; i++) {
    for (int j = i; j < 7; j++) {
      pile.emplace_back(new Card(i, j));
    }
  }
  std::random_shuffle(pile.begin(), pile.end());
}

card_ptr_t Board::drawCard() {
  auto rv = pile.back();
  pile.pop_back();
  return rv;
}
