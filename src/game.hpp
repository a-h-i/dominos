#include "board.hpp"
#include "player.hpp"
#include <vector>

class Game {
private:
  Board board;
  int currentPlayer;
public:
  std::vector<Player> players;
  explicit Game(int numPlayers);
  Player & getCurrentPlayer();
};
