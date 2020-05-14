#include <iostream>

using namespace std;
//Class
class Brawler{
  public:
    void setname();
//    void takehit();
//    void givehit(Brawler &Reciver,int &Manacost,int &dmg);
    bool checkHP();
    class Spells{
      public:
        void castspell(Brawler &Foe, Brawler &Attacker);
        int Manacost;
        int dmg;
	string name;
      private:
    }Spell[4];
  private:
    string name;
    int HP;
    int Mana;
};
//roll for hit
bool rollhit(){
  auto number = (rand() % 20) + 1;
  if (number >= 7)
    return (true);
  else 
    return (false);	
}
//roll for spell (enemy)
int rollenemyattack(){
  auto number = (rand() % 4) + 1;
  return number - 1;
}
//check for hit and send manacost and dmg
void Brawler::Spells::castspell(Brawler& Foe,Brawler& Attacker){
  if(rollhit() == true){
    if(Attacker.Mana >= Manacost){
      Attacker.Mana = Attacker.Mana - Manacost;
      Foe.HP = Foe.HP - dmg; 
      cout << "I will use " << name << endl;      
    }
  else
    cout << "The spell missed..." << endl;
  }
}
//to check if player or enemy is dead
bool Brawler::checkHP(){
  if(HP < 0)
    return (true);
  else
    return (false);
}

//into for name
void Brawler::setname(){
  string fake;
  name = "Dunce";
  cout << "..what's your name" << endl;
  cin >> fake;
  cout << fake << "? What kind of a shit name is that?? Im gonna call you: " << name << endl;
  cout << "And on our left: The conterster" << name << endl;
}
//check for mana and remove it
void Brawler::givehit(Brawler &Reciver){
  if(Mana >= Manacost){
    Mana = Mana - Manacost;
    Reciver.gethit(player.dmg);
  }
}
//check for hp and remove
void Brawler::gethit(Damage){
  Foe.HP = Foe.HP - dmg;
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
  Brawler Mage;
  Brawler Warrior;
  Brawler Enemy;
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
  

  cout << "Welcome to the Brawler's Leauge! Two brave champions has made it to the finals! On the left: Our reigning champion KALGOOR THE BEAKER OF WORLDS!!!" << endl;
  Player.setname();
  cout << "Let the game begin!" << endl;
//int lvl för att fixa fler bossar
  //Boss 1
  while (Player.checkHP() == true || Enemy.checkHP() == true){
    int x;
    if(attacker.front() == Player)
      for(int a=0;a<4; a++){ 
        cout << Player::Spell[a].name << ": " << a << endl;
      } 
      cin >> x;
      Brawler::Spell[x].castspell(Enemy, Player);
      attacker.push_back(Player);
      attacker.pop_front()
    else
      rollenemyattack(x);
      Brawler::Spell[x].castspell(Player, Enemy);
      attacker.push_back(Enemy);
      attacker.pop_front()
  }
  //Boss2 etc
}

		
