#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "monsterCard.hpp"
#include "weatherCard.hpp"
#include <fstream>

using namespace std;

class game {
private:
  vector<vector<vector<card*> > > battleField;
  uint8_t weatherField;
  vector<player> players;
  vector<card*> cardPool;
  void castCard(int p, card * toBeCasted);
public:
  void initializeCardBase(string filePath);
  void showCard();
  game();
  ~game() {
    for (int i=0;i<cardPool.size();i++) {
      delete cardPool[i];
    }
    cardPool.clear();
  }
  void initializePlayerDeck();
  //void gameProcess();
  int matchProcess();
  int matchResolution();
  void showBattleField();
  //void showWeatherField();
};

#endif
