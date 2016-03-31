#ifndef MONSTERCARD_HPP
#define MONSTERCARD_HPP
#include "card.hpp"
#include <iostream>

using namespace std;

class monsterCard : public card {
private:
  uint8_t attack;
  uint8_t position;
  string getPosition() {
    switch (position) {
      case 0: return "Close Combat";
      case 1: return "Ranged Combat";
      case 2: return "Siege Combat";
      default: return "Close Combat";
    }
  }
  
public:
  void print_card() {
    cout<<"Card name: "<< card_name <<endl;
    cout<<"Attack: "<< (unsigned int)attack <<endl;
    cout<<"Position: "<< getPosition() <<endl;
    cout<<"\"" << card_description << "\"\n";
  }
  void set_attack(uint8_t atk) { attack=atk;}
  void set_position(uint8_t pos) { position=pos;}
  void cast (int p, vector<vector<vector<card *> > >& battleField, uint8_t& weatherField) {
    battleField[p][position].push_back((card*)this);
  }
  int get_attack() {return (int)attack;}
  monsterCard(uint8_t id, uint8_t atk, uint8_t pos) 
    : card(id), attack(atk), position(pos) {}
  ~monsterCard(){}
};
    
#endif
