#include "game.hpp"

using namespace std;

int main() {
  game g;
  g.initializeCardBase("./card.file");
  g.initializePlayerDeck();
  g.gameProcess();
  return 0;
}
