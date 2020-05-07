#include <iostream>

using namespace std;

class Brawler{
  public:
    void setname();
    void changebrawlerstats();
    class spells{
      public:
        void castspell();
        int Manacost;
        int dmg;
      private:
    }Spell[4];
  private:
    string name;
    int HP;
    int Mana;
};
bool rollhit(){
  auto number = (rand() % 20) + 1;
  if (number =< 7){
    return (true);
  else 
    return (false);
  }	
}

void Brawler::setname(){
  cout << "..what's your name" << endl;
  cin >> name;
  cout << endl << "And on our left: The conterster" << name << endl;
}

void Brawler::changebrawlerstats(Manacost, Damage){
  Mana = Mana - Manacost;
  
}

void Brawler::Spells::castspell(){
  if(rollhit() == true)
    changebrawlerstats(Manacost, dmg);
  else
    cout << "The spell missed" << endl;
}



int main(){
  Brawler::Spells Punch;
    Punch.Manacost = 0;
    Punch.dmg  = 5;
  Brawler::Spells Pickacard;
    Pickacard.Manacost = 10;
    Pickacard.dmg  = 25;
  Brawler::Spells Coinflip;
    Coinflip.Manacost = 20;
    Coinflip.dmg  = 30;
  Brawler::Spells Vanish;
    Vanish.Manacost = 30;
    Vanish.dmg  = 0;
  Brawler::Spells Swordtoss;
    Swordtoss.Manacost = 10;
    Swordtoss.dmg  = 25;
  Brawler::Spells Leapofdoom;
    Leap.Manacost = 10;
    Leap.dmg  = 25;
  Brawler::Spells Runinfear;
    Runinfear.Manacost = 10;
    Runinfear.dmg  = 25;
  Brawler::Spells Brutalsmash;
    Brutalsmash.Manacost = 0;
    Brutalsmash.dmg  = 15;
  Brawler::Spells Firestorm;
    Firestrom.Manacost = 0;
    Firestorm.dmg  = 25;
  Brawler::Spells Killonsight;
    Killonsight.Manacost = 0;
    Killonsight.dmg  = 35;

  Brawler Mage;
  Brawler Warrior;
  Brawler Enemy;
  Mage.spell[0] = Punch;
  Mage.spell[1] = Pickacard;
  Mage.spell[2] = Coinflip;
  Mage.spell[3] = Vanish;
  Warrior.spell[0] = Punch;
  Warrior.spell[1] = Swordtoss;
  Warrior.spell[2] = Leapofdoom;
  Warrior.spell[3] = Runinfear;
  Enemy.spell[0] = Brutalsmash;
  Enemy.spell[1] = Firestorm;
  Enemy.spell[2] = Killonsight;
  Enemy.spell[3] = Brutalsmash;
  string player;
  cout << "pick a class: Mage or Warrior?" << endl;
  cin >> player;

  cout << "Welcome to the Brawler guild! Two brave champions has made it to the finals! On the left: Our reigning champion KALGOOR!!!" << endl;
  player.setname();
}

		
