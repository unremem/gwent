//
//  monsterCard.hpp
//
//  Created by Tianyi Yang on 3/23/16.
//////////////////////////////////////////////////////

#ifndef MONSTERCARD_HPP
#define MONSTERCARD_HPP
#include "card.hpp"
#include <iostream>

using namespace std;

class monsterCard : public card {
private:
/*
 * the attack and position information of the monster card
*/
  uint8_t attack;
  uint8_t position;
/*
 * getPosition is a helper function for printing the card
 * translate the 8 bit unsigned int of position into string
*/
  string getPosition() {
    switch (position) {
      case 0: return "Close Combat";
      case 1: return "Ranged Combat";
      case 2: return "Siege Combat";
      default: return "Close Combat";
    }
  }
  
public:
/*
 * implementation of print_card() for monsterCard class
*/
  void print_card() {
    cout<<"Card name: "<< card_name <<endl;
    cout<<"Attack: "<< (unsigned int)attack <<endl;
    cout<<"Position: "<< getPosition() <<endl;
    cout<<"\"" << card_description << "\"\n";
  }
/*
 * set the new properties of monsterCard class
*/
  void set_attack(uint8_t atk) { attack=atk;}
  void set_position(uint8_t pos) { position=pos;}
/*
 * implementation of cast()
 * just to push the card into the proper position in battleField
*/
  void cast (int p, vector<vector<vector<card *> > >& battleField, uint8_t& weatherField) {
    battleField[p][position].push_back((card*)this);
  }
/*
 * get_attack() is just a helper function for match resolution to extract the attack info from the card
*/
  int get_attack() {return (int)attack;}
/*
 * the constructor and destructor of monsterCard class
*/
  monsterCard(uint8_t id, uint8_t atk, uint8_t pos) 
    : card(id), attack(atk), position(pos) {}
  ~monsterCard(){}
};
    
#endif
