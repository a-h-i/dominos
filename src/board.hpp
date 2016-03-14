#pragma once
#include <vector>


enum Direction { LEFT, RIGHT};

struct Card {
  int left, right;
  Card * left_attached, * right_attached;
  Card(int l, int r) : left(l), right(r), left_attached(nullptr),
    right_attached(nullptr) {}
};

class Board {
private:
  std::vector<Card> pile;
public:
  Board();
};
