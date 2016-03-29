#include "player.hpp"

/*void player::addCardToDeck(unordered_map<,uint8_t, card*>& card_pool, uint8_t card_id) {
  player::deck.push_back(card_pool[card_id]);
  usable_card++;
  return;
}*/

void player::addCardToDeck(card* newCard) {
  player::deck.push_back(newCard);
  usable_card++;
  return;
}

void player::remCardFromDeck(int index) {
  player::deck.erase(player::deck.begin()+index);
  usable_card--;
  return;
}

void player::printDeck() {
  for (int i=0;i<usable_card;i++) {
    std::cout<< i<< ": ";
    player::deck[i]->print_card();
  }
  return;
}

void player::printHand() {
  int sz=player::hand.size();
  for (int i=0;i<sz;i++) {
    std::cout<< i<< ": ";
    player::hand[i]->print_card();
  }
  return;
}

void player::drawCard() {
  if (player::usable_card==0) {
    cout<< "There's no card in player: "<< player_id<< "\'s deck!\n";
    return;
  }
  int index=std::rand() % usable_card;
  player::hand.push_back(player::deck[index]);
  card* tmp = player::deck[index];
  player::deck[index]=player::deck[--usable_card];
  player::deck[usable_card]=tmp;
  return;
}

void player::remCardFromHand(int index) {
  player::hand.erase(player::hand.begin()+index);
  return;
}

card* player::playCard(int index) {
  card* tmp=player::hand[index];
  player::remCardFromHand(index);
  return tmp;
}
