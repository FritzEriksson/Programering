#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <TGUI/TGUI.hpp>
#include <stdlib.h>
#include <time.h>

const int w_width = 600;
const int w_height= 700;

//Randomizer för Knappar
//---------------------------------------------------------------------------------------------------------------------------
void signalHandler(tgui::EditBox::Ptr editbox){	
	auto number = (rand() % 15) + 1;
	editbox->setText(std::to_string(number));
}
//Spara Gubben
//---------------------------------------------------------------------------------------------------------------------------
void sparning(tgui::EditBox::Ptr Strshow, tgui::EditBox::Ptr Dexshow, tgui::EditBox::Ptr Conshow, tgui::EditBox::Ptr Intshow, tgui::EditBox::Ptr TitelBox, tgui::EditBox::Ptr NameBox){
	std::string Name = NameBox->getText();
	std::string Titel = TitelBox->getText();	
	std::string Str = Strshow->getText();
	std::string Dex = Dexshow->getText();
	std::string Con = Conshow->getText();
	std::string Int = Intshow->getText();
	std::fstream Spar ("Spar1.txt", std::ios::in | std::ios::app);
	if (Spar.is_open()){
		Spar << "{" << std::endl << Titel << std::endl << Name << std::endl << Str << std::endl << Dex << std::endl << Con << std::endl << Int << std::endl;
		Spar.close();
	}
}
//Ladda den sparade gubben
//---------------------------------------------------------------------------------------------------------------------------
void laddning(tgui::EditBox::Ptr Strshow, tgui::EditBox::Ptr Dexshow, tgui::EditBox::Ptr Conshow, tgui::EditBox::Ptr Intshow, tgui::EditBox::Ptr TitelBox, tgui::EditBox::Ptr NameBox){
	sf::RenderWindow window3(sf::VideoMode(510, 220), "Loadwindow");
	tgui::Gui gui3{window3};
	sf::Font font;
	if (!font.loadFromFile("PiratesBay.ttf")){
		std::cout << "font not found" << std::endl;
	}
//editbox och var
	tgui::EditBox::Ptr Load = tgui::EditBox::create();
		gui3.add(Load);
		Load->setPosition(50, 100);
		Load->setSize(300, 50);
		Load->setTextSize(40);
	sf::Text Tutori;
		Tutori.setFont(font);
		Tutori.setString("Type the name of the Character\n you wish to load");
		Tutori.setCharacterSize(35);
		Tutori.setFillColor(sf::Color(255, 255, 255));
		Tutori.setPosition(sf::Vector2f(7.f, 7.f));
		Tutori.setStyle(sf::Text::Bold);
	int a = 0;
	std::string Gubbe[5];
	std::ifstream Ladd ("Spar1.txt");
	std::string x;
	std::string line;
	std::string test;
//Loop
	while (window3.isOpen())
	{
		sf::Event event3;
		while (window3.pollEvent(event3))
		{
			if (event3.key.code == sf::Keyboard::Return)
			{
				x = Load->getText();
				while (Ladd.is_open())
				{
					getline(Ladd, line);
					if (line == "{")
					{
						getline(Ladd, test);
						if (test == x)
						{
							for(int a=0; a<5; a++)
							{
								getline(Ladd, Gubbe[a]);
							}
							TitelBox->setText(x);
							NameBox->setText(Gubbe[0]);
							Strshow->setText(Gubbe[1]);
							Dexshow->setText(Gubbe[2]);
							Conshow->setText(Gubbe[3]);
							Intshow->setText(Gubbe[4]);
							Ladd.close();
							window3.close();
						}
						else
							test = "";
					}					
				}
			}
			if (event3.type == sf::Event::Closed)
				window3.close();		
			gui3.handleEvent(event3);
		}
	window3.clear();
	gui3.draw();
	window3.draw(Tutori);
	window3.display();	
	}
}
//Statwindow
//---------------------------------------------------------------------------------------------------------------------------
void statwindow(tgui::EditBox::Ptr Strshow, tgui::EditBox::Ptr Dexshow, tgui::EditBox::Ptr Conshow, tgui::EditBox::Ptr Intshow){
	sf::RenderWindow window2(sf::VideoMode(350, 500), "Statwindow");
	tgui::Gui gui2{window2};
	sf::Font font;
	if (!font.loadFromFile("PiratesBay.ttf")){
		std::cout << "font not found" << std::endl;
	}
//Matte och omvandling	
	std::string mstr = Strshow->getText();
	std::string mdex = Dexshow->getText();
	std::string mcon = Conshow->getText();
	std::string mint = Intshow->getText();
	int str = std::stoi(mstr);
	int dex = std::stoi(mdex);
	int con = std::stoi(mcon);
	int inte = std::stoi(mint);
	int Damage = (str*2 + dex*0.2);
	int Health = str*2 + con*4;
	int Dodge = 0.1*dex;
	int Mana = inte*10+100;
	int Speech = inte*3-Damage;
	if (Speech < 0){
		Speech = 0;
	}
	int Charisma = Speech + Health -str;
	if (Charisma < 0){
		Charisma = 0;
	}
	int Luck = Charisma + Dodge + dex;
	int Agillity = dex*3 + str*0.3;
//Editboxar secondary stats
	tgui::EditBox::Ptr Dmgview = tgui::EditBox::create();
		gui2.add(Dmgview);
		Dmgview->setPosition(110, 200);
		Dmgview->setSize(50, 25);
		Dmgview->setTextSize(20);
		Dmgview->setText(std::to_string(Damage));
		Dmgview->setReadOnly();
	tgui::EditBox::Ptr HPview = tgui::EditBox::copy(Dmgview);
		gui2.add(HPview);
		HPview->setPosition(110, 100);
		HPview->setText(std::to_string(Health));
	tgui::EditBox::Ptr Manaview = tgui::EditBox::copy(Dmgview);
		gui2.add(Manaview);
		Manaview->setPosition(110, 150);
		Manaview->setText(std::to_string(Mana));
	tgui::EditBox::Ptr Agiview = tgui::EditBox::copy(Dmgview);
		gui2.add(Agiview);
		Agiview->setPosition(110, 250);
		Agiview->setText(std::to_string(Agillity));
	tgui::EditBox::Ptr Dodview = tgui::EditBox::copy(Dmgview);
		gui2.add(Dodview);
		Dodview->setPosition(110, 300);
		Dodview->setText(std::to_string(Dodge));
	tgui::EditBox::Ptr Speechview = tgui::EditBox::copy(Dmgview);
		gui2.add(Speechview);
		Speechview->setPosition(110, 350);
		Speechview->setText(std::to_string(Speech));
	tgui::EditBox::Ptr Chaview = tgui::EditBox::copy(Dmgview);
		gui2.add(Chaview);
		Chaview->setPosition(110, 400);
		Chaview->setText(std::to_string(Charisma));
	tgui::EditBox::Ptr Luckview = tgui::EditBox::copy(Dmgview);
		gui2.add(Luckview);
		Luckview->setPosition(110, 450);
		Luckview->setText(std::to_string(Luck));
//Text
	sf::Text text;
		text.setFont(font);
		text.setString("HP\n\nMana\n\nDamage\n\nAgillity\n\nDodge\n\nSpeech\n\nCharisma\n\nLuck");
		text.setCharacterSize(22);
		text.setFillColor(sf::Color(255, 255, 255));
		text.setPosition(sf::Vector2f(7.f, 100.f));
		text.setStyle(sf::Text::Bold);
	sf::Text title;
		title.setFont(font);
		title.setString("Secondary stats");
		title.setCharacterSize(45);
		title.setFillColor(sf::Color(255, 255, 255));
		title.setPosition(sf::Vector2f(7.f, 7.f));
		title.setStyle(sf::Text::Bold);
//loop stats
	while (window2.isOpen())
	{
		sf::Event event2;
		while (window2.pollEvent(event2))
		{
			if (event2.type == sf::Event::Closed)
				window2.close();		
			gui2.handleEvent(event2);
		}
	window2.clear();
	gui2.draw();
	window2.draw(title);
	window2.draw(text);
	window2.display();	
	}		
}
//main
//---------------------------------------------------------------------------------------------------------------------------
int main()
{
	sf::RenderWindow window(sf::VideoMode(w_width, w_height), "DND CharCreationTM");
	tgui::Gui gui{window};
	srand (time(NULL));
//Laddning av font och texturer
	sf::Font font;
	if (!font.loadFromFile("PiratesBay.ttf")){
		std::cout << "font not found" << std::endl;
	}
	sf::Texture texture;
	if (!texture.loadFromFile("Gubbe.jpg"))
	{
	    std::cout << "texture not found" << std::endl;
	}
// Knappar, Editboxar, text och annan GUI (Förstaskärm) 
	tgui::Button::Ptr Strknapp = tgui::Button::create();
		gui.add(Strknapp);
		Strknapp->setPosition(50, 250);
		Strknapp->setSize(50, 50);
			tgui::EditBox::Ptr Strshow = tgui::EditBox::create();
			gui.add(Strshow);
			Strshow->setPosition(110, 250);
			Strshow->setSize(50, 50);
			Strshow->setTextSize(25);
			Strshow->setReadOnly();
	tgui::Button::Ptr Dexknapp = tgui::Button::copy(Strknapp);
		gui.add(Dexknapp);
		Dexknapp->setPosition(50, 300);
			tgui::EditBox::Ptr Dexshow = tgui::EditBox::copy(Strshow);
			gui.add(Dexshow);
			Dexshow->setPosition(110, 300);
	tgui::Button::Ptr Conknapp = tgui::Button::copy(Strknapp);
		gui.add(Conknapp);
		Conknapp->setPosition(50, 400);
			tgui::EditBox::Ptr Conshow = tgui::EditBox::copy(Strshow);
			gui.add(Conshow);
			Conshow->setPosition(110, 400);
	tgui::Button::Ptr Intknapp = tgui::Button::copy(Strknapp);
		gui.add(Intknapp);
		Intknapp->setPosition(50, 450);
			tgui::EditBox::Ptr Intshow = tgui::EditBox::copy(Strshow);
			gui.add(Intshow);
			Intshow->setPosition(110, 450);
	tgui::Button::Ptr Randknapp = tgui::Button::copy(Strknapp);
		gui.add(Randknapp);
		Randknapp->setPosition(80, 510);
	tgui::Button::Ptr Statknapp = tgui::Button::copy(Strknapp);
		gui.add(Statknapp);
		Statknapp->setPosition(500, 510);
	tgui::Button::Ptr Sparknapp = tgui::Button::copy(Strknapp);
		gui.add(Sparknapp);
		Sparknapp->setPosition(500, 230);
	tgui::Button::Ptr Laddknapp = tgui::Button::copy(Strknapp);
		gui.add(Laddknapp);
		Laddknapp->setPosition(500, 320);
	tgui::EditBox::Ptr NameBox = tgui::EditBox::create();
		gui.add(NameBox);
		NameBox->setPosition(170, 600);
		NameBox->setSize(300, 50);
		NameBox->setTextSize(40);
	tgui::EditBox::Ptr TitelBox = tgui::EditBox::create();
		gui.add(TitelBox);
		TitelBox->setPosition(100, 655);
		TitelBox->setSize(400, 25);
		TitelBox->setTextSize(20);
//sf::Text
	sf::Text titel;
		titel.setFont(font);
		titel.setString("DND CharCreationTM");
		titel.setCharacterSize(50);
		titel.setFillColor(sf::Color(255, 255, 255));
		titel.setPosition(sf::Vector2f(50.f, 10.f));
		titel.setStyle(sf::Text::Bold | sf::Text::Underlined);
	sf::Text SpLaGe;
		SpLaGe.setFont(font);
		SpLaGe.setString("Save Character\n\n\n\nLoad Character\n\n\n\n\n\n\n\nGenerate stats");
		SpLaGe.setCharacterSize(20);
		SpLaGe.setFillColor(sf::Color(255, 255, 255));
		SpLaGe.setPosition(sf::Vector2f(465.f, 200.f));
		SpLaGe.setStyle(sf::Text::Bold);
	sf::Text Stat;
		Stat.setFont(font);
		Stat.setString("Str\n\nDex\n\n\nCon\n\nInt");
		Stat.setCharacterSize(25);
		Stat.setFillColor(sf::Color(255, 255, 255));
		Stat.setPosition(sf::Vector2f(5.f, 250.f));
		Stat.setStyle(sf::Text::Bold);
	sf::Text Titeldone;
		Titeldone.setFont(font);
		Titeldone.setString("");
		Titeldone.setCharacterSize(25);
		Titeldone.setFillColor(sf::Color(255, 255, 255));
		Titeldone.setPosition(sf::Vector2f(110.f, 130.f));
		Titeldone.setStyle(sf::Text::Bold);
	sf::Text Namedone;
		Namedone.setFont(font);
		Namedone.setString("");
		Namedone.setCharacterSize(50);
		Namedone.setFillColor(sf::Color(255, 255, 255));
		Namedone.setPosition(sf::Vector2f(110.f, 80.f));
		Namedone.setStyle(sf::Text::Bold);
	sf::Text Titleplate;
		Titleplate.setFont(font);
		Titleplate.setString("Title");
		Titleplate.setCharacterSize(25);
		Titleplate.setFillColor(sf::Color(255, 255, 255));
		Titleplate.setPosition(sf::Vector2f(25.f, 650.f));
		Titleplate.setStyle(sf::Text::Bold);
	sf::Text Nameplate;
		Nameplate.setFont(font);
		Nameplate.setString("Name");
		Nameplate.setCharacterSize(50);
		Nameplate.setFillColor(sf::Color(255, 255, 255));
		Nameplate.setPosition(sf::Vector2f(25.f, 595.f));
		Nameplate.setStyle(sf::Text::Bold);
	sf::Text Rand;
		Rand.setFont(font);
		Rand.setString("Rand");
		Rand.setCharacterSize(25);
		Rand.setFillColor(sf::Color(255, 255, 255));
		Rand.setPosition(sf::Vector2f(18.f, 510.f));
		Rand.setStyle(sf::Text::Bold);
//Signaler
	Strknapp->connect("pressed", signalHandler, std::ref(Strshow));
	Dexknapp->connect("pressed", signalHandler, std::ref(Dexshow));
	Conknapp->connect("pressed", signalHandler, std::ref(Conshow));
	Intknapp->connect("pressed", signalHandler, std::ref(Intshow));
	Randknapp->connect("pressed", signalHandler, std::ref(Strshow));
	Randknapp->connect("pressed", signalHandler, std::ref(Dexshow));
	Randknapp->connect("pressed", signalHandler, std::ref(Conshow));
	Randknapp->connect("pressed", signalHandler, std::ref(Intshow));
	Statknapp->connect("pressed", statwindow, std::ref(Strshow), std::ref(Dexshow), std::ref(Conshow), std::ref(Intshow));
	Sparknapp->connect("pressed", sparning, std::ref(Strshow), std::ref(Dexshow), std::ref(Conshow), std::ref(Intshow), std::ref(NameBox), std::ref(TitelBox));
	Laddknapp->connect("pressed", laddning, std::ref(Strshow), std::ref(Dexshow), std::ref(Conshow), std::ref(Intshow), std::ref(NameBox), std::ref(TitelBox));
//Sprite
	sf::Sprite Gubbe;
		Gubbe.setTexture(texture);
		Gubbe.setPosition(sf::Vector2f(170.f, 200.f)); 
		Gubbe.setScale(sf::Vector2f(0.5f, 0.5f)); 
// Loop Main
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Return)		
				Namedone.setString(NameBox->getText());
			if (event.key.code == sf::Keyboard::Return)
				Titeldone.setString(TitelBox->getText());
			if (event.type == sf::Event::Closed)
				window.close();		
			gui.handleEvent(event);
		}
	window.clear();
	gui.draw();
	window.draw(titel);
	window.draw(SpLaGe);
	window.draw(Stat);
	window.draw(Titeldone);
	window.draw(Namedone);
	window.draw(Titleplate);
	window.draw(Nameplate);
	window.draw(Rand);
	window.draw(Gubbe);
	window.display();
	}
}
