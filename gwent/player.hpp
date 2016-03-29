#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "monsterCard.hpp"
#include "weatherCard.hpp"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class player {
private:
  vector<card*> deck;
  vector<card*> hand;
  int usable_card;
  int player_id;
public:
  bool won;
  bool end_turn;
  player(int id) : player_id(id), won(false), end_turn(false), usable_card(0) {}
  ~player() { deck.clear();hand.clear();}
  //void addCardToDeck(unordered_map<,uint8_t, card*>& card_pool, uint8_t card_id);
  void addCardToDeck(card* newCard);
  void remCardFromDeck(int index);
  void printDeck();
  void drawCard();
  void remCardFromHand(int index);
  void printHand();
  card * playCard(int index);
};

#endif
