#include <iostream>

using namespace std;

class Brawler{
	public:
		void setname();
		void setHP();
		void setMana();
		class Spellbook{
			public:
				void castspell();
				void choosespell();
			private:
				int Manacons;
				int Dmg;
		}Spells[3];
	private:
		String name;
		int HP;
		int Mana;
}Brawler[2];

void Brawler::Spellbook::choosespell(){
	int x;
	cout << "DU Öppnar :\nTobbe trollkarls Magilåda\nPick a card 1.\nPlaceholder 2.\nBenen på ryggen 3." << endl;
	cin >> x;
	void Brawler::Spellbook::Spells[x]::castspell();
	
}

void Brawler::Spellbook::Spells::castspell(){
	void Brawler[caster+1]::setHP();
	void Brawler[caster]::setMana();
	
}

void Brawler::setname(){
	cout << "And on the right we have our contestor and i dont know his name... whats your name champion?" << endl;
	cin >> z;
	Brawler[0].name = z;
	cout << endl << Brawler[0].name << endl;

}

bool rollhit(){
	auto number = (rand() % 20) + 1;
	if (number =< 7){
		return (true);
	else 
		return (false);
	}
	
}


class Brawler{
	public:
		void setname();
		void getname();
		void spellcast();
		void changebrawlerstats();
		class spells
			public:
				void castspell();
			private:
				string spell;
				int Manacost;
				int dmg;
	private:
		string name;
		int HP;
		int Mana;
};

void Brawler::setname(){
	cout << "..what's your name" << endl;
	cin >> name;
	cout << endl << "And on our left: The conterster" << name << endl;
}

bool rollhit(){
	auto number = (rand() % 20) + 1;
	if (number =< 7){
		return (true);
	else 
		return (false);
	}
	
}

int main(){
	Brawler::Spells Pickacard
	Brawler::Spells Placeholder
	Brawler::Spells Run;
	
	Brawler Player;
	Brawler Enemy;
	
	cout << "Welcome to the Brawler guild! Two brave champions has made it to the finals! On the left: Our reigning champion KALGOOR!!!" << endl;
	Player.setname();
}

		
