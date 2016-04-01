//
//  player.hpp
//
//  Created by Tianyi Yang on 3/25/16.
//////////////////////////////////////////////////////

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
/*
 * deck is a vector holding all the cards in the player's deck
*/
  vector<card*> deck;
/*
 * hand is a vector holding all the cards in the player's hand currently
*/
  vector<card*> hand;
/*
 * usable_card represents how many cards are there still usable in the user's deck
 * whenever a card is draw from the deck to the user's hand, it's no longer usable to the deck
*/
  int usable_card;
/*
 * player_id is the id of the player
 * not useful in current version, but might be useful when multiple users are involved
*/
  int player_id;

public:
/*
 * won represents whether a player has won a round since whoever wins 2 rounds first wins the game
*/
  bool won;
/*
 * end_turn represents whether a player has decided to end his turn for this round
*/
  bool end_turn;
/*
 * the constructor and destructor of the player class
*/
  player(int id) : player_id(id), won(false), end_turn(false), usable_card(0) {}
  ~player() { deck.clear();hand.clear();}
/*
 * addCardToDeck is called when the game tries to initialize the player's deck
 * it adds the pointer to a card into the player's deck
*/
  void addCardToDeck(card* newCard);
/*
 * remCardFromDeck is called when a card is draw from the deck or the player doesn't want the card in his deck anymore
*/
  void remCardFromDeck(int index);
/*
 * print all the cards in the deck
*/
  void printDeck();
/*
 * draw a card from the deck randomly to the player's hand
*/
  void drawCard();
/*
 * remCardFromHand is called when a card is played by the player to the battle field
 * remove the card with the index from the user's hand vector
*/
  void remCardFromHand(int index);
/*
 * print all the cards in the user's hand
*/
  void printHand();
/*
 * the player tries to play a card to the battle field
 * this method return a pointer to the casted card
*/
  card * playCard(int index);
/*
 * reset the end turn status of the player for the next round
*/
  void resetPlayer();
/*
 * return whether there are still cards in the player's hand
*/
  bool handEmpty();
};

#endif
