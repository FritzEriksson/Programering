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
    string name;
    void gethit(Brawler &Foe,int y);
    bool checkHP();
    void Castspell(Brawler &attacker, Brawler &Foe, int x, int y, int h, string n);
    void sethp(Brawler &Foe);
    void Showhpmana(Brawler &Foe);
    void youwin();
    class Spells{
      public:
        void spellinfo(Brawler &Foe, Brawler &attacker);
        int Manacost;
        int dmg;
        int heal;
	string name;
      private:
    }Spell[4];
    friend bool operator==(class Brawler& lhs, class Brawler& rhs);
  private:
    int HP;
    int Mana;
}Fighter[3];
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
//send spell info to castspell
void Brawler::Spells::spellinfo(Brawler &Foe, Brawler &attacker){
  int x = Manacost;
  int y = dmg;
  int h = heal;
  string n = name;
  attacker.Castspell(attacker, Foe, x, y, h, n);
}
//to check if player or enemy is dead
bool Brawler::checkHP(){
  if(HP > 0)
    return (true);
  else
    return (false);
}
//check for hit, mana, HP and remove it
void Brawler::Castspell(Brawler &attacker, Brawler &Foe, int x, int y, int h, string n){
  if(Mana >= x){
    Mana = Mana - x;
    if(rollhit() == true){
      Foe.gethit(Foe, y);
      HP = HP + h;
      cout << "Announcer: What a gracefull move! " << attacker.name <<" is using the narrow timewindow to cast: " << n << endl;
    }      
    else
      cout << "Announcer: The spell missed.. what a disaster.." << endl;
  }
  else
    cout << "You need more mana!" << endl;
  cout << setfill('=') << setw(13) << " \n";
  cout << setfill(' ');
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
void Brawler::youwin(){
  string x;
  HP = -2;
  cout << "congrats you win! Hope you will play this X-stream game soon!" << endl;
  cout << endl << endl << "type anything to exit" << endl;
  cin >> x;
}
int main(){
//Spellbook
//__________________________________________
  Brawler::Spells Punch;
    Punch.Manacost = 0;
    Punch.dmg = 10;
    Punch.heal = 0;
    Punch.name = "Punch";
  Brawler::Spells Frostbolt;
    Frostbolt.Manacost = 15;
    Frostbolt.heal = 0;
    Frostbolt.dmg  = 25;
    Frostbolt.name = "Frostbolt";
  Brawler::Spells Firebolt;
    Firebolt.Manacost = 30;
    Firebolt.heal = 0;
    Firebolt.dmg  = 40;
    Firebolt.name = "Firebolt";
  Brawler::Spells HeroicSlash;
    HeroicSlash.Manacost = 10;
    HeroicSlash.heal = 0;
    HeroicSlash.dmg  = 25;
    HeroicSlash.name = "Heroic Slash";
  Brawler::Spells Leapofdoom;
    Leapofdoom.Manacost = 10;
    Leapofdoom.heal = -5;
    Leapofdoom.dmg  = 25;
    Leapofdoom.name = "Leap of doom";
  Brawler::Spells HPManareg;
    HPManareg.Manacost = -10;
    HPManareg.heal = 30;
    HPManareg.dmg  = 0;
    HPManareg.name = "Potion of regenation";
  Brawler::Spells Brutalsmash;
    Brutalsmash.Manacost = 0;
    Brutalsmash.heal = 0;
    Brutalsmash.dmg  = 15;
    Brutalsmash.name = "Brutal smash";
  Brawler::Spells Firestorm;
    Firestorm.Manacost = 0;
    Firestorm.heal = 0;
    Firestorm.dmg  = 25;
    Firestorm.name = "Firestorm";
  Brawler::Spells Killonsight;
    Killonsight.Manacost = 0;
    Killonsight.heal = 0;
    Killonsight.dmg  = 35;
    Killonsight.name = "Kill on sight";
//set Enemy spells
  Fighter[1].name = "Kalgoor";
  Fighter[2].name = "Punchus";
  Fighter[1].Spell[0] = Brutalsmash;
  Fighter[1].Spell[1] = Firestorm;
  Fighter[1].Spell[2] = Killonsight;
  Fighter[1].Spell[3] = Brutalsmash;
  Fighter[2].Spell[0] = Punch;
  Fighter[2].Spell[1] = Punch;
  Fighter[2].Spell[2] = Punch;
  Fighter[2].Spell[3] = HPManareg;
//_______________________________
//Welcome
  cout << "You are now playing: BloodFist X-tream IIV" << endl;
//Class pick
  int input;
  cout << "\nPick your Fighter:\n1:Mage \n2:Warrior" << endl;
  cin >> input;
  cout << "Please enter your name" << endl;
  cin >> Fighter[0].name;
  cout << "EPIC" << endl;
  //Set player spells and class
  if (input == 1){
    //Mage
    Fighter[0].Spell[0] = Punch;
    Fighter[0].Spell[1] = Frostbolt;
    Fighter[0].Spell[2] = Firebolt;
    Fighter[0].Spell[3] = HPManareg;
  }
  if (input == 2){
    //Warrior
    Fighter[0].Spell[0] = Punch;
    Fighter[0].Spell[1] = HeroicSlash;
    Fighter[0].Spell[2] = Leapofdoom;
    Fighter[0].Spell[3] = HPManareg;
  }
  if (input < 1 || 2 < input)
    cout << "You have to choices.. just pick one..." << endl;
  int lvl = 1;     
  list<Brawler> attacker = {Fighter[0], Fighter[lvl]};
  
  cout << "\nAnnouncer: Welcome all to the Brawlers Guild! Today we have some great matches lined up for you all!" << endl;
  cout << setfill('=') << setw(26) << " \n";
  cout << setfill(' ');
  Fighter[0].sethp(Fighter[lvl]);
  while(Fighter[0].checkHP() == true){
    cout << "Announcer: For our " << lvl << " match. "<< Fighter[0].name << " will be facing the mighty " << Fighter[lvl].name << endl;
    cout << "Lets see if he will come out alive..." << endl;
    cout << "Announcer: BEGIN!!!!!" << endl;
    while (Fighter[0].checkHP() == true && Fighter[lvl].checkHP() == true){
      int z;
      Fighter[0].Showhpmana(Fighter[lvl]);
      if(attacker.front() == Fighter[0]){
        cout << "You know this is your time to strike, your options are limited and you narrowed it down to four options." << endl << endl;
        for(int a=0;a<3; a++){ 
          cout << a << ": " << Fighter[0].Spell[a].name << endl << "Manacost: " << Fighter[0].Spell[a].Manacost << endl << "Damage: " << Fighter[0].Spell[a].dmg << endl;
        }
        //För att det inte ska stå -manacost och för att visa hpreg
        cout << 3 << ": " << Fighter[0].Spell[3].name << endl << "Manareg: 10" << endl << "HPreg: " << Fighter[0].Spell[3].heal << endl; 
        cin >> z;
        Fighter[0].Spell[z].spellinfo(Fighter[lvl], Fighter[0]);
        attacker.push_back(Fighter[0]);
        attacker.pop_front();
      }
      else
        cout << "Announcer: " << Fighter[lvl].name << " is on the move.." << endl;
        z = rollenemyattack(z);
        Fighter[lvl].Spell[z].spellinfo(Fighter[0], Fighter[lvl]);
        attacker.push_back(Fighter[lvl]);
        attacker.pop_front();
    }
    if(Fighter[0].checkHP() == false){
      cout << "Announcer: You are dead" << endl;
    }
    if(Fighter[lvl].checkHP() == false){
      lvl = lvl + 1;
      attacker.clear();
      attacker.push_back(Fighter[0]);
      attacker.push_back(Fighter[lvl]);
      Fighter[0].sethp(Fighter[lvl]);
      cout << "Announcer: You killed " << Fighter[lvl-1].name << " ...I did not expect that!" << endl;
    }
    if(lvl == 3){
    Fighter[0].youwin();
    }
  }
}

		
