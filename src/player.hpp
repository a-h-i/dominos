#pragma once
#include "board.hpp"
#include <memory>
class Player {
private:
  std::vector<card_ptr_t> hand;
public:
  Player();
  void add_card(card_ptr_t c) {hand.push_back(c);}
};
