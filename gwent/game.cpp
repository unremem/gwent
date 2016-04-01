//
//  game.cpp
//
//  Created by Tianyi Yang on 3/27/16.
//////////////////////////////////////////////////////

#include "game.hpp"

using namespace std;

/*
 * the constructor of game class
 * initialize the players vector and the battleField vectors
 * the first dimension of this vector represents each player, in this case is 2
 * the second dimension of this vector represents the position of the monster card, including 0 - close combat, 1 - ranged combat, and 2 - Siege Combat.
 * the most inner vector represents the pointer to each card in the battlefield.
*/
game::game() {
  for (int i=0;i<2;i++) {
    players.push_back(player(i));
  }
  battleField=vector<vector<vector<card*> > >(2,vector<vector<card*> >(3,vector<card*>()));
}

/*
 * initializePlayerDeck is a demo function to initialize the players deck
 * todo: implement a function to enable user to select card from card base to make their own deck
*/
void game::initializePlayerDeck() {
  for (int p=0;p<2;p++) {
    for (int c=0;c<20;c++) {
      players[p].addCardToDeck(game::cardPool[c]);
    }
  }
}

/*
 * the game main function. implement the whole game process.
*/
void game::gameProcess() {
  /*
  each player draw 10 cards from their own deck.
  todo: enable player to put at most 2 cards back to the deck and redraw 2 cards.
  */
  for (int p=0;p<2;p++) 
    for (int i=0;i<10;i++) 
      players[p].drawCard();

  /*
  the real game process. the player who wins 2 rounds first wins the game.
  */
  while (1) {
    /*
    run the process for each round. res represents the result of each round.
    1 - player 0 won this round
    2 - player 1 won this round
    3 - draw
    */
    int res = game::matchProcess();
    switch (res) {
      case 1: cout<< "Player 0 won the round!\n";break;
      case 2: cout<< "Player 1 won the round!\n";break;
      default: cout<< "Draw!\n";break;
    }
    for (int p=0;p<2;p++) {
      if (res & (0x1<<p)) {
        if (players[p].won) {
          cout<< "Player " << p << " won the game!\n";
          return;
        }
        else players[p].won=true;
      }
      //after each round, reset the players' end turn status
      players[p].resetPlayer();
      //and discard all the cards on the battle field
      for (int i=0;i<3;i++) 
        battleField[p][i].clear();
    }
    // as well as the weather cards
    weatherField=0;
  }
}

/*
 * matchProcess is the method to process a round of a game
 * in each turn, the cards in the players' hands will be printed on the screen
 * each player is able to play the cards in their hands until they choose to end their turn
 * when both of the players end their turn, will call the matchResolution function to judge the result.
*/
int game::matchProcess() {
  
  int p=0;
  while (!players[0].end_turn || !players[1].end_turn) {
    /*
    if a player has ended his turn or has no card in hand, then skip his turn.
    */
    if (players[p].end_turn || players[p].handEmpty()) {players[p].end_turn=true;p^=0x1;continue;}
    cout<< "Player " << p << "'s turn!\n";
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
    int inCard=0;
    cin>>inCard;
    game::castCard(p,players[p].playCard(inCard));
    p^=0x1;
  }
  return matchResolution();
}

/*
 * matchResolution function return an integer representing the result of a round
 * 1 - player 0 won this round
 * 2 - player 1 won this round
 * 3 - draw
*/
int game::matchResolution() {
  //res is the total damage of each player
  int res [2]={};
  for (int p=0;p<2;p++) {
    for (int i=0;i<3;i++) {
      //if the weather card for the current position is activated, then the damage of each card should be 1
      //e.g. if Biting Frost is activated then all the close combat monster cards on the field will become a 1 damage unit
      if (weatherField & (0x1<<i)) res[p]+=battleField[p][i].size();
      else {
        for (int mCard=0; mCard<battleField[p][i].size(); mCard++) {
          monsterCard* monster=(monsterCard*)battleField[p][i][mCard];
          res[p]+=monster->get_attack();
        }
      }
    }
  }
  return res[0]>res[1]?1: (res[0]==res[1]? 3:2);
}

/*
 * castCard is the method to cast a card from a user's hand
 * the first parameter is the id of the player
 * the second parameter is the pointer to the card to be casted
*/
void game::castCard(int p, card * toBeCasted) {
  //call the virtual function of each card to cast itself to the proper field
  toBeCasted->cast(p, game::battleField, game::weatherField);
  cout<< "Card:\n";
  toBeCasted->print_card();
  cout<< "is casted to the Battle Field!\n";
}

/*
 * getId is a helper function to extract the 8 bit integer information from a string, and at the same time remove it from the string
*/
uint8_t getId(string& line) {
  int end=0;
  string res;
  while (line[end]!=' ') end++;
  res=line.substr(0,end);
  line=line.substr(end+1);
  return (uint8_t) atoi(res.c_str());
}

/*
 * initializeCardBase function is called when the game is initialized
 * it reads in the address from filePath and extract the card data into the cardPool vector in the game class
 * each 2 lines in the card.file represents a card
*/
void game::initializeCardBase(string filePath) {
  ifstream cardBase(filePath);
  string line;
  srand(time(NULL));
  if (cardBase.is_open()) {
    while (getline(cardBase, line)) {
      uint8_t card_id = getId(line);
      /* 
      the MSB of the card_id represents whether it's a monster or weather card
      1 - monster card
      0 - weather card
      */
      if (card_id & 0x80) {
        /*
        the next integer come after card_id is the attack of the monster card
        and then the position of the monster card
        */
        uint8_t atk = getId(line);
        uint8_t pos = getId(line);
        card * mCard = new monsterCard(card_id, atk, pos);
        mCard->set_name(line);
        getline(cardBase, line);
        mCard->set_description(line);
        game::cardPool.push_back(mCard);
      }
      else {
        /*
        the next integer come after card_id is the weather type of the weather card        
        */
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

/*
  showCard prints out the cards in the cardPool
  */
void game::showCard() {
  for (int i=0;i<cardPool.size();i++) 
    cardPool[i]->print_card();
  return;
}

/*
  showBattleField is a test function to show all the cards on the battle field.
  */
void game::showBattleField() {
  for (int p=0;p<2;p++) {
    cout<< "Player " << p << " field:\n";
    for (int row=0;row<3;row++) {
      for (int mCard=0; mCard<battleField[p][row].size(); mCard++)
        battleField[p][row][mCard]->print_card();
    }
  }
}

/*void game::showWeatherField() {
  for (int wCard=0; wCard<4; wCard++) wCard->print_card();
}*/
