#pragma once
#include <vector>
#include <memory>

enum Direction { LEFT, RIGHT};

struct Card {
  int left, right;
  std::shared_ptr<Card> left_attached, right_attached;
  Card(int l, int r) : left(l), right(r), left_attached(nullptr),
    right_attached(nullptr) {}
};


typedef std::shared_ptr<Card> card_ptr_t;

class Board {
private:
  std::vector<card_ptr_t> pile;
public:
  Board();
};
