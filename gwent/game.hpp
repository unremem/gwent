#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "monsterCard.hpp"
#include "weatherCard.hpp"
#include <fstream>

using namespace std;

class game {
private:
  vector<vector<vector<monsterCard*> > > battleField;
  vector<player> players;
  vector<card*> cardPool;
  void castCard(card * toBeCasted);
public:
  void initializeCardBase(string filePath);
  void showCard();
  game();
  ~game() {
    for (card* c:cardPool) {
      delete c;
    }
    cardPool.clear();
  }
  void initializePlayerDeck();
  void gameProcess();
  int matchProcess();
  int matchResolution();
};

#endif
