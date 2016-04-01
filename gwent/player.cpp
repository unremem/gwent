//
//  player.cpp
//
//  Created by Tianyi Yang on 3/25/16.
//////////////////////////////////////////////////////

#include "player.hpp"

/*
 * addCardToDeck is called when the game tries to initialize the player's deck
 * it adds the pointer to a card into the player's deck and increment the usable card by 1
*/
void player::addCardToDeck(card* newCard) {
  player::deck.push_back(newCard);
  usable_card++;
  return;
}

/*
 * remCardFromDeck is called when a card is draw from the deck or the player doesn't want the card in his deck anymore
 * it decreases the usable card by 1
*/
void player::remCardFromDeck(int index) {
  player::deck.erase(player::deck.begin()+index);
  usable_card--;
  return;
}

/*
 * print all the cards in the deck
*/
void player::printDeck() {
  for (int i=0;i<usable_card;i++) {
    std::cout<< i<< ": ";
    player::deck[i]->print_card();
  }
  return;
}

/*
 * print all the cards in the user's hand
*/
void player::printHand() {
  int sz=player::hand.size();
  for (int i=0;i<sz;i++) {
    std::cout<< i<< ": ";
    player::hand[i]->print_card();
  }
  return;
}

/*
 * draw a card from the deck randomly to the player's hand
*/
void player::drawCard() {
  //if there's no usable card in the deck, then we cannot do the draw operation
  if (player::usable_card==0) {
    cout<< "There's no card in player: "<< player_id<< "\'s deck!\n";
    return;
  }
  //get a random index from the usable cards
  int index=std::rand() % usable_card;
  //put it in hand
  player::hand.push_back(player::deck[index]);
  //and swap the card to the back of the card array, at the same time, decrease the usable cards, so that this card will never be picked again from the deck vector
  card* tmp = player::deck[index];
  player::deck[index]=player::deck[--usable_card];
  player::deck[usable_card]=tmp;
  return;
}

/*
 * remCardFromHand is called when a card is played by the player to the battle field
 * remove the card with the index from the user's hand vector
*/
void player::remCardFromHand(int index) {
  player::hand.erase(player::hand.begin()+index);
  return;
}

/*
 * the player tries to play a card to the battle field
 * this method return a pointer to the casted card
*/
card* player::playCard(int index) {
  card* tmp=player::hand[index];
  player::remCardFromHand(index);
  return tmp;
}

/*
 * reset the end turn status of the player for the next round
*/
void player::resetPlayer() {
  player::end_turn=false;
}

/*
 * return whether there are still cards in the player's hand
*/
bool player::handEmpty() {
  return player::hand.empty();
}
