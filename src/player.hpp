#pragma once
#include "board.hpp"
#include <memory>
#include <string>
class Player {
public:
  std::vector<card_ptr_t> hand;
  const std::string name;
  Player(const std::string &name);
  void addCard(card_ptr_t c) {hand.push_back(c);}
};
