#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("lunchds.ttf"))
	{
		//error
	}

	logotexture.loadFromFile("zsk.png");
	logo.setTexture(logotexture);
	logo.setScale(0.5, 0.5);
	logo.setPosition(sf::Vector2f(100,100));

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Start gry");
	menu[0].setPosition(sf::Vector2f(width/2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Wczytaj gre");
	menu[1].setPosition(sf::Vector2f(width/2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("TOP score");
	menu[2].setPosition(sf::Vector2f(width/2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Autorzy");
	menu[3].setPosition(sf::Vector2f(width/2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("Wyjscie");
	menu[4].setPosition(sf::Vector2f(width/2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(logo);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}