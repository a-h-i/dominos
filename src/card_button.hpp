#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
   #include <wx/wx.h>
#endif
#include "card.hpp"
#include "game.hpp"

class CardButton {
private:
  Game * game;
  Card card;
public:
  CardButton(Game * game, const Card &card);
};
