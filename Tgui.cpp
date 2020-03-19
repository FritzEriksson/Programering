#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <TGUI/TGUI.hpp>

const int w_width = 600;
const int w_height= 700;

//Randomizer för Knappar
void signalHandler(tgui::EditBox::Ptr editbox){
	auto number = (rand() % 15) + 1;
	editbox->setText(std::to_string(number));
}
//Statwindow
void statwindow(tgui::EditBox::Ptr Strshow, tgui::EditBox::Ptr Dexshow, tgui::EditBox::Ptr Conshow, tgui::EditBox::Ptr Intshow){
	sf::RenderWindow window2(sf::VideoMode(w_width, w_width), "Statwindow");
	tgui::Gui gui2{window2};
	int str = std::stoi(Strshow->getText());
	int dex = std::stoi(Dexshow->getText());
//	std::string Damage = (str*2 + dex*0.2);
//	int Health = Str*0.5 + con*4;
//	int Dodge = 0.1*Dex;
//	int Mana = intellect*10+100;
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
	window2.display();	
	}		
}
//main
int main()
{
	sf::RenderWindow window(sf::VideoMode(w_width, w_height), "DND CharCreationTM");
	tgui::Gui gui{window};

	sf::Font font;
	if (!font.loadFromFile("PiratesBay.ttf")){
		std::cout << "font not found" << std::endl;
	}
// Knappar och dess GUI 
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
			sf::Text Str;
				Str.setFont(font);
				Str.setString("Str");
				Str.setCharacterSize(25);
				Str.setFillColor(sf::Color(255, 255, 255));
				Str.setPosition(sf::Vector2f(5.f, 250.f));
				Str.setStyle(sf::Text::Bold);
	tgui::Button::Ptr Dexknapp = tgui::Button::create();
		gui.add(Dexknapp);
		Dexknapp->setPosition(50, 300);
		Dexknapp->setSize(50, 50);
			tgui::EditBox::Ptr Dexshow = tgui::EditBox::create();
			gui.add(Dexshow);
			Dexshow->setPosition(110, 300);
			Dexshow->setSize(50, 50);
			Dexshow->setTextSize(25);
			Dexshow->setReadOnly();
			sf::Text Dex;
				Dex.setFont(font);
				Dex.setString("Dex");
				Dex.setCharacterSize(25);
				Dex.setFillColor(sf::Color(255, 255, 255));
				Dex.setPosition(sf::Vector2f(5.f, 300.f));
				Dex.setStyle(sf::Text::Bold);
	tgui::Button::Ptr Conknapp = tgui::Button::create();
		gui.add(Conknapp);
		Conknapp->setPosition(50, 400);
		Conknapp->setSize(50, 50);
			tgui::EditBox::Ptr Conshow = tgui::EditBox::create();
			gui.add(Conshow);
			Conshow->setPosition(110, 400);
			Conshow->setSize(50, 50);
			Conshow->setTextSize(25);
			Conshow->setReadOnly();
			sf::Text Con;
				Con.setFont(font);
				Con.setString("Con");
				Con.setCharacterSize(25);
				Con.setFillColor(sf::Color(255, 255, 255));
				Con.setPosition(sf::Vector2f(5.f, 400.f));
				Con.setStyle(sf::Text::Bold);
	tgui::Button::Ptr Intknapp = tgui::Button::create();
		gui.add(Intknapp);
		Intknapp->setPosition(50, 450);
		Intknapp->setSize(50, 50);
			tgui::EditBox::Ptr Intshow = tgui::EditBox::create();
			gui.add(Intshow);
			Intshow->setPosition(110, 450);
			Intshow->setSize(50, 50);
			Intshow->setTextSize(25);
			Intshow->setReadOnly();
			sf::Text Int;
				Int.setFont(font);
				Int.setString("Int");
				Int.setCharacterSize(25);
				Int.setFillColor(sf::Color(255, 255, 255));
				Int.setPosition(sf::Vector2f(5.f, 450.f));
				Int.setStyle(sf::Text::Bold);
	tgui::Button::Ptr Randknapp = tgui::Button::create();
		gui.add(Randknapp);
		Randknapp->setPosition(80, 510);
		Randknapp->setSize(50, 50);
		sf::Text Rand;
			Rand.setFont(font);
			Rand.setString("Rand");
			Rand.setCharacterSize(25);
			Rand.setFillColor(sf::Color(255, 255, 255));
			Rand.setPosition(sf::Vector2f(18.f, 510.f));
			Rand.setStyle(sf::Text::Bold);
	Strknapp->connect("pressed", signalHandler, std::ref(Strshow));
	Dexknapp->connect("pressed", signalHandler, std::ref(Dexshow));
	Conknapp->connect("pressed", signalHandler, std::ref(Conshow));
	Intknapp->connect("pressed", signalHandler, std::ref(Intshow));
	Randknapp->connect("pressed", signalHandler, std::ref(Strshow));
	Randknapp->connect("pressed", signalHandler, std::ref(Dexshow));
	Randknapp->connect("pressed", signalHandler, std::ref(Conshow));
	Randknapp->connect("pressed", signalHandler, std::ref(Intshow));
	tgui::Button::Ptr Statknapp = tgui::Button::create();
		gui.add(Statknapp);
		Statknapp->setPosition(500, 510);
		Statknapp->setSize(50, 50);
		sf::Text Stat;
			Stat.setFont(font);
			Stat.setString("Generate stats");
			Stat.setCharacterSize(20);
			Stat.setFillColor(sf::Color(255, 255, 255));
			Stat.setPosition(sf::Vector2f(470.f, 490.f));
			Stat.setStyle(sf::Text::Bold);
	Statknapp->connect("pressed", statwindow, std::ref(Strshow), std::ref(Dexshow), std::ref(Conshow), std::ref(Intshow));
 
//EditBoxar med utskrift
	tgui::EditBox::Ptr NameBox = tgui::EditBox::create();
		gui.add(NameBox);
		NameBox->setPosition(150, 600);
		NameBox->setSize(300, 50);
		NameBox->setTextSize(40);
		sf::Text Nameplate;
			Nameplate.setFont(font);
			Nameplate.setString("Name");
			Nameplate.setCharacterSize(50);
			Nameplate.setFillColor(sf::Color(255, 255, 255));
			Nameplate.setPosition(sf::Vector2f(25.f, 595.f));
			Nameplate.setStyle(sf::Text::Bold);
			sf::Text Namedone;
				Namedone.setFont(font);
				Namedone.setString("");
				Namedone.setCharacterSize(50);
				Namedone.setFillColor(sf::Color(255, 255, 255));
				Namedone.setPosition(sf::Vector2f(110.f, 80.f));
				Namedone.setStyle(sf::Text::Bold);
	tgui::EditBox::Ptr TitelBox = tgui::EditBox::create();
		gui.add(TitelBox);
		TitelBox->setPosition(100, 655);
		TitelBox->setSize(400, 25);
		TitelBox->setTextSize(20);
		sf::Text Titleplate;
			Titleplate.setFont(font);
			Titleplate.setString("Title");
			Titleplate.setCharacterSize(25);
			Titleplate.setFillColor(sf::Color(255, 255, 255));
			Titleplate.setPosition(sf::Vector2f(25.f, 650.f));
			Titleplate.setStyle(sf::Text::Bold);
			sf::Text Titeldone;
				Titeldone.setFont(font);
				Titeldone.setString("");
				Titeldone.setCharacterSize(25);
				Titeldone.setFillColor(sf::Color(255, 255, 255));
				Titeldone.setPosition(sf::Vector2f(110.f, 130.f));
				Titeldone.setStyle(sf::Text::Bold);
	sf::Text titel;
	titel.setFont(font);
	titel.setString("DND CharCreationTM");
	titel.setCharacterSize(50);
	titel.setFillColor(sf::Color(255, 255, 255));
	titel.setPosition(sf::Vector2f(50.f, 10.f));
	titel.setStyle(sf::Text::Bold);

	sf::RectangleShape Box(sf::Vector2f(120.f, 50.f));
	Box.setFillColor(sf::Color(33, 33, 33));
	Box.setPosition(sf::Vector2f(200.f, 200.f));
	Box.setSize(sf::Vector2f(250.f, 350.f));

// Loop
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
//Utritningar
	window.clear();
	gui.draw();
	window.draw(titel);
	window.draw(Nameplate);
	window.draw(Namedone);
	window.draw(Titleplate);
	window.draw(Titeldone);
	window.draw(Str);
	window.draw(Dex);
	window.draw(Con);
	window.draw(Int);	
	window.draw(Box);
	window.draw(Rand);
	window.draw(Stat);
	window.display();
	}
}
