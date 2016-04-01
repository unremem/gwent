//
//  game.hpp
//
//  Created by Tianyi Yang on 3/27/16.
//////////////////////////////////////////////////////

#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "monsterCard.hpp"
#include "weatherCard.hpp"
#include <fstream>

using namespace std;

class game {
private:
/*
 * battleField is the battle field for the monster cards
 * the first dimension of this vector represents each player, in this case is 2
 * the second dimension of this vector represents the position of the monster card, including 0 - close combat, 1 - ranged combat, and 2 - Siege Combat.
 * the most inner vector represents the pointer to each card in the battlefield.
*/
  vector<vector<vector<card*> > > battleField;
/*
 * weatherField represents the weather condition of the battle field bit wisely.
 * the LSB (1st bit) represents Biting Frost, which affect the close combat damage
 * the 2nd bit represents Impenetrable Fog, which affect the ranged combat damage
 * the 3rd bit represents Torrential Rain, which affect the siege combat damage
*/
  uint8_t weatherField;
/*
 * players is a vector for the instances of players
*/
  vector<player> players;
/*
 * cardPool is the pool for all the cards in the database
*/
  vector<card*> cardPool;
/*
 * castCard is the method to cast a card from a user's hand
 * the first parameter is the id of the player
 * the second parameter is the pointer to the card to be casted
*/
  void castCard(int p, card * toBeCasted);
/*
 * matchProcess is the method to process a round of a game
 * in each turn, the cards in the players' hands will be printed on the screen
 * each player is able to play the cards in their hands until they choose to end their turn
 * when both of the players end their turn, will call the matchResolution function to judge the result.
*/
  int matchProcess();
/*
 * matchResolution function return an integer representing the result of a round
 * 1 - player 0 won this round
 * 2 - player 1 won this round
 * 3 - draw
*/
  int matchResolution();

public:
/*
 * initializeCardBase function is called when the game is initialized
 * it reads in the address from filePath and extract the card data into the cardPool vector in the game class
 * each 2 lines in the card.file represents a card
*/
  void initializeCardBase(string filePath);
/*
 * showCard prints out the cards in the cardPool
*/
  void showCard();
/*
 * the constructor and destructor of game class
*/
  game();
  ~game() {
    //free all the memory allocated by the initializeCardBase function
    for (int i=0;i<cardPool.size();i++) {
      delete cardPool[i];
    }
    cardPool.clear();
  }
/*
 * initializePlayerDeck is a demo function to initialize the players deck
 * todo: implement a function to enable user to select card from card base to make their own deck
*/
  void initializePlayerDeck();
/*
 * the game main function. implement the whole game process.
*/
  void gameProcess();
/*
 * showBattleField is a test function to show all the cards on the battle field.
*/
  void showBattleField();
};

#endif
