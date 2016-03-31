#include "game.hpp"

using namespace std;

int main() {
  game g;
  g.initializeCardBase("./card.file");
  g.initializePlayerDeck();
  int res=g.matchProcess();
  cout << res << endl;
  return 0;
}
