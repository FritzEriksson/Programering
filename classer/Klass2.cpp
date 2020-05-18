#include <iostream>
#include <list>
#include <string.h>
#include <iomanip>

using namespace std;
//Class
class Brawler{
  public:
    Brawler(string name_=""){
      name = name_;
    }
    void setname();
    void gethit(Brawler &Foe,int y);
    bool checkHP();
    void Manafunc(Brawler &Foe, int x, int y);
    void sethp(Brawler &Foe);
    void Showhpmana(Brawler &Foe);
    class Spells{
      public:
        void castspell(Brawler &Foe, Brawler &attacker);
        int Manacost;
        int dmg;
	string name;
      private:
    }Spell[4];
    friend bool operator==(class Brawler& lhs, class Brawler& rhs);
  private:
    string name;
    int HP;
    int Mana;
};
//make the list work
bool operator==(class Brawler& lhs, class Brawler& rhs){
  return lhs.name == rhs.name;
}

//roll for hit
bool rollhit(){
  auto number = (rand() % 20) + 1;
  if (number >= 7)
    return (true);
  else 
    return (false);	
}
//roll for spell (enemy)
int rollenemyattack(int z){
  z = (rand() % 4) + 1;
  return z = z - 1;
}
//check for hit and send manacost and dmg
void Brawler::Spells::castspell(Brawler &Foe,Brawler &attacker){
  if(rollhit() == true){
    int x = Manacost;
    int y = dmg;
    attacker.Manafunc(Foe, x, y);
    cout << "Announcer: What a gracefull move, the champion is using his narrow timewindow to cast: " << name << endl;
  }      
  else
    cout << "Announcer: The spell missed.. what a disaster.." << endl;
}
//to check if player or enemy is dead
bool Brawler::checkHP(){
  if(HP > 0)
    return (true);
  else
    return (false);
}
//Check mana and remove
void Brawler::Manafunc(Brawler &Foe, int x, int y){
  if(Mana >= x){
    Mana = Mana - x;
    Foe.gethit(Foe, y);
  }
  else
    cout << "I need more mana!" << endl;
}
//into for name
void Brawler::setname(){
  string fake;
  
  cout << "Announcer: ..what's your name" << endl;
  cin >> fake;
  cout << "Announcer: Ok? What kind of a shit name is that?? Im gonna call you: " << name << endl;
  cout << "Announcer: And on our left: The conterster" << name << endl;
}

//remove hp
void Brawler::gethit(Brawler &Foe, int y){
  HP = HP - y;
}
void Brawler::sethp(Brawler &Foe){
  HP = 100;
  Foe.HP = 100;
  Mana = 100;
  Foe.Mana = 100;
}
void Brawler::Showhpmana(Brawler &Foe){
  cout << setfill('=') << setw(26) << " \n";
  cout << setfill(' ');
  cout << "Player Stats" << endl;
  cout << "HP: " << HP << endl;
  cout << "Mana: " << Mana << endl;
  cout << setfill('=') << setw(13) << " \n";
  cout << setfill(' ');
  cout << "Enemy Stats" << endl;
  cout << "HP: " << Foe.HP << endl;
  cout << "Mana: " << Foe.Mana << endl;
  cout << setfill('=') << setw(13) << " \n";
  cout << setfill(' ');
}
int main(){
//Spellbook
  Brawler::Spells Punch;
    Punch.Manacost = 0;
    Punch.dmg = 5;
    Punch.name = "Punch";
  Brawler::Spells Pickacard;
    Pickacard.Manacost = 10;
    Pickacard.dmg  = 25;
    Pickacard.name = "Pick a card";
  Brawler::Spells Coinflip;
    Coinflip.Manacost = 20;
    Coinflip.dmg  = 30;
    Coinflip.name = "Coinflip";
  Brawler::Spells Vanish;
    Vanish.Manacost = 30;
    Vanish.dmg  = 0;
    Vanish.name = "Vanish";
  Brawler::Spells Swordtoss;
    Swordtoss.Manacost = 10;
    Swordtoss.dmg  = 25;
    Swordtoss.name = "Swordtoss";
  Brawler::Spells Leapofdoom;
    Leapofdoom.Manacost = 10;
    Leapofdoom.dmg  = 25;
    Leapofdoom.name = "Leap of doom";
  Brawler::Spells Runinfear;
    Runinfear.Manacost = 10;
    Runinfear.dmg  = 25;
    Runinfear.name = "Run in fear";
  Brawler::Spells Brutalsmash;
    Brutalsmash.Manacost = 0;
    Brutalsmash.dmg  = 15;
    Brutalsmash.name = "Brutal smash";
  Brawler::Spells Firestorm;
    Firestorm.Manacost = 0;
    Firestorm.dmg  = 25;
    Firestorm.name = "Firestorm";
  Brawler::Spells Killonsight;
    Killonsight.Manacost = 0;
    Killonsight.dmg  = 35;
    Killonsight.name = "Kill on sight";
//set Brawler spells
  Brawler Mage("Mage");
  Brawler Warrior("Warrior");
  Brawler Enemy("Enemy");
  Brawler Player;
  Mage.Spell[0] = Punch;
  Mage.Spell[1] = Pickacard;
  Mage.Spell[2] = Coinflip;
  Mage.Spell[3] = Vanish;
  Warrior.Spell[0] = Punch;
  Warrior.Spell[1] = Swordtoss;
  Warrior.Spell[2] = Leapofdoom;
  Warrior.Spell[3] = Runinfear;
  Enemy.Spell[0] = Brutalsmash;
  Enemy.Spell[1] = Firestorm;
  Enemy.Spell[2] = Killonsight;
  Enemy.Spell[3] = Brutalsmash;
//Class pick
  int input;
  cout << "pick a class: 1=Mage or 2=Warrior?" << endl;
  cin >> input;
  //COPY VAL TILL PLAYER
  if (input == 1)
    Brawler Player = Mage;
  if (input == 2)
    Brawler Player = Warrior;
  if (input < 1 || 2 < input)
    cout << "You have to choices.. just pick one..." << endl;
       
  list<Brawler> attacker = {Player, Enemy};
  

  cout << "Announcer: Welcome to the Brawler's Leauge! Two brave champions has made it to the finals! On the left: Our reigning champion KALGOOR THE BEAKER OF WORLDS!!!" << endl;
  Player.setname();
  cout << "Announcer: Let the game begin!" << endl;
  cout << setfill('=') << setw(26) << " \n";
  cout << setfill(' ');
//int lvl för att fixa fler bossar
  //Boss 1
  Player.sethp(Enemy);
  while (Player.checkHP() == true || Enemy.checkHP() == true){
    int z;
    if(attacker.front() == Player){
      cout << "Announcer: Dunce is on the move.." << endl;
      cout << "You know this is your time to strike, your options are limited and you narrowed it down to four options." << endl << endl;
      for(int a=0;a<4; a++){ 
        cout << a << ": " << Player.Spell[a].name << endl;
      } 
      cin >> z;
      Player.Spell[z].castspell(Enemy, Player);
      attacker.push_back(Player);
      attacker.pop_front();
      Player.Showhpmana(Enemy);
    }
    else
      cout << "Announcer: Kalgoor is on the move.." << endl;
      rollenemyattack(z);
      Enemy.Spell[z].castspell(Player, Enemy);
      attacker.push_back(Enemy);
      attacker.pop_front();
      Player.Showhpmana(Enemy);
  }
  //Boss2 etc
}

		
