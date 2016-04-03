//
//  card.hpp
//
//  Created by Tianyi Yang on 3/23/16.
//////////////////////////////////////////////////////

#ifndef CARD_HPP
#define CARD_HPP
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

class card {
/*
 * to be inherited by the child classes, so use protected here
*/
protected:
/*
 * the id of the card
 * with the MSB representing the type of the card - monster card or weather card
*/
  uint8_t card_id;
/*
 * basic card properties
*/
  string card_name;
  string card_description;

public:
/*
 * the constructors of card class
*/
  card() : card_id(0) {}
  card(uint8_t id) : card_id(id) {}
/*
 * set the basic properties of the cards
*/
  void set_id(uint8_t id) { card_id=id;}
  void set_name(string name) { card_name=name;}
  void set_description(string description) { card_description=description;}
/*
 * pure virtual function for the child classes
 * to print this card and cast this card on the battleField
*/
  virtual void cast (int p, vector<vector<vector<card *> > >& battleField, uint8_t& weatherField)=0;
  virtual void print_card () =0;
/*
 * virtual destructor for the specific cards to delete themselves
*/
  virtual ~card(){}
};

#endif
