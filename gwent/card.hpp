#ifndef CARD_HPP
#define CARD_HPP
#include <stdint.h>
#include <string>

using namespace std;

class card {
protected:
  uint8_t card_id;
  string card_name;
  string card_description;

public:
  void (*cast)(int,vector<vector<vector<monsterCard *> > >&,uint8_t&);
  card() : card_id(0) {}
  card(uint8_t id) : card_id(id) {}
  virtual void print_card () =0;
  void set_id(uint8_t id) { card_id=id;}
  void set_name(string name) { card_name=name;}
  void set_description(string description) { card_description=description;}
  virtual ~card(){}
};

#endif
