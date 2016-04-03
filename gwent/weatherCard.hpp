//
//  weatherCard.hpp
//
//  Created by Tianyi Yang on 3/23/16.
//////////////////////////////////////////////////////

#ifndef WEATHERCARD_HPP
#define WEATHERCARD_HPP
#include "card.hpp"
#include <iostream>

using namespace std;

class weatherCard : public card {
private:
/*
 * weather_effect represents how this card will change the current weather condition 
 * if it's 0x01 (Biting Frost), then it will change the attack of all the close combat unit to 1
 * if it's 0x02 (Impenetrable Fog), then it will change the attack of all the ranged combat unit to 1
 * if it's 0x04 (Torrential Rain), then it will change the attack of all the siege combat unit to 1
 * if it's 0x00 (Clear Day), then all the current weather card is removed from battle field
*/
  uint8_t weather_effect;
  
public:
/*
 * implementation of print_card() for weatherCard class
*/
  void print_card() {
    cout<<"Card name: "<< card_name <<endl;
    cout<<"\"" << card_description << "\"\n";
  }
/*
 * implementation of cast()
 * just change the weatherField of game class according to the card weather_effect
*/
  void cast(int p, vector<vector<vector<card*> > >& battleField, uint8_t& weatherField) {
    if (!weather_effect) weatherField=0;
    else weatherField |= weather_effect;
  }
/*
 * set the new properties of weatherCard class
*/
  void set_weather_effect(uint8_t wea) { weather_effect=wea;}
/*
 * the constructor and destructor of monsterCard class
*/
  weatherCard(uint8_t id, uint8_t wea) : card(id), weather_effect(wea) {}
  ~weatherCard(){}
};
    
#endif
