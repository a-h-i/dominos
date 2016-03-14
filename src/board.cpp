#include "board.hpp"
Board::Board() {
  pile.reserve(28);
  for (int i = 0; i < 7; i++) {
    for (int j = i; i < 7; j++) {
      pile.emplace_back(i, j);
    }
  }
}
