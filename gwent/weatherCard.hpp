#ifndef WEATHERCARD_HPP
#define WEATHERCARD_HPP
#include "card.hpp"
#include <iostream>

using namespace std;

class weatherCard : public card {
private:
  uint8_t weather_effect;
  void castWeatherCard(int p, vector<vector<vector<monsterCard*> > >& battleField, uint8_t& weatherField) {
    if (!weather_effect) weatherField=0;
    else weatherField |= weather_effect;
  }

public:
  void print_card() {
    cout<<"Card name: "<< card_name <<endl;
    cout<<"\"" << card_description << "\"\n";
  }
  void set_weather_effect(uint8_t wea) { weather_effect=wea;}
  weatherCard(uint8_t id, uint8_t wea) : card(id), weather_effect(wea) {
    cast=&weatherField;
  }
  ~weatherCard(){}
};
    
#endif
