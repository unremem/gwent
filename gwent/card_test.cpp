#include "monsterCard.hpp"
#include "weatherCard.hpp"

using namespace std;

int main() {
  monsterCard * mCard = new monsterCard(0x1,0x5,0x1);
  card * wCard = new weatherCard(0x2,0x1);
  mCard->set_name("hehe");
  mCard->set_description("hehe");
  mCard->print_card();
  delete mCard;
  delete wCard;
  return 0;
}
