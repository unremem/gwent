#include "game.hpp"

using namespace std;

int main() {
  game g;
  g.initializeCardBase("./card.file");
  g.showCard();
  return 0;
}
