#include "game.hpp"
#include <string>
Game::Game(int numPlayers) : currentPlayer(0) {
  for(int i = 0; i < numPlayers; i++) {
    players.emplace_back(std::string("Player ") + std::to_string(i));
  }
  for(auto & player : players) {
    for(int i = 0; i < 7; i++) {
      player.addCard(board.drawCard());
    }
  }
}


Player & Game::getCurrentPlayer() {
  return players[currentPlayer];
}
