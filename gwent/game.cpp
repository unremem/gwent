#include "game.hpp"

using namespace std;

game::game() {
  for (int i=0;i<2;i++) {
    players.push_back(player(i));
  }
}

void game::initializePlayerDeck() {
  for (int p=0;p<2;p++) {
    for (int c=0;c<40;c++) {
      players[p].addCardToDeck(game::cardPool[c]);
    }
  }
}

int matchProcess() {
  for (int p=0;p<2;p++) 
    for (int i=0;i<10;i++) 
      players[p].drawCard();
  int p=0;
  while (!players[0].end_turn && !players[1].end_turn) {
    if (players[p].end_turn) p^=0x1;continue;
    players[p].printHand();
    cout<< "End your turn?(y/n)\n";
    char endTurn='y';
    cin>>endTurn;
    if (endTurn=='y') {
      players[p].end_turn=true;
      p^=0x1;
      continue;
    }
    cout<< "Which card are you playing?\n";
    cin>>inCard;
    castCard(players[p].playCard(inCard));
    p^=0x1;
  }
  return matchResolution();
}

uint8_t getId(string& line) {
  int end=0;
  string res;
  while (line[end]!=' ') end++;
  res=line.substr(0,end);
  line=line.substr(end+1);
  return (uint8_t) atoi(res.c_str());
}

void game::initializeCardBase(string filePath) {
  ifstream cardBase(filePath);
  string line;
  if (cardBase.is_open()) {
    while (getline(cardBase, line)) {
      uint8_t card_id = getId(line);
      if (card_id & 0x80) {
        uint8_t atk = getId(line);
        uint8_t pos = getId(line);
        card * mCard = new monsterCard(card_id, atk, pos);
        mCard->set_name(line);
        getline(cardBase, line);
        mCard->set_description(line);
        game::cardPool.push_back(mCard);
      }
      else {
        uint8_t wea = getId(line);
        card * wCard = new weatherCard(card_id, wea);
        wCard->set_name(line);
        getline(cardBase, line);
        wCard->set_description(line);
        game::cardPool.push_back(wCard);
      }
    }
    cardBase.close();
  }
  else cout<< "Unable to open Card Base!\n";
  return;
}

void game::showCard() {
  for (int i=0;i<cardPool.size();i++) 
    cardPool[i]->print_card();
  return;
}
  
