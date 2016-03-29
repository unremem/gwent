#include "player.hpp"

using namespace std;

int main() {
  srand(time(NULL));
  monsterCard * mCard = new monsterCard(0x1,0x5,0x1);
  card * wCard = new weatherCard(0x2,0x1);
  mCard->set_name("hehe");
  mCard->set_description("hehe");
  wCard->set_name("weather card");
  wCard->set_description("Sunny");
  player p1 (1);
  card * tmp=mCard;
  cout<<"Deck function test\n";
  p1.addCardToDeck(tmp);
  p1.addCardToDeck(wCard);
  p1.printDeck();
  p1.remCardFromDeck(0);
  p1.remCardFromDeck(0);
  p1.addCardToDeck(tmp);
  p1.addCardToDeck(wCard);
  cout<<"Hand function test\n";
  p1.drawCard();
  p1.printDeck();
  p1.printHand();
  p1.drawCard();
  //p1.printDeck();
  p1.printHand();
  p1.drawCard();
  
  delete mCard;
  delete wCard;
  return 0;
}
