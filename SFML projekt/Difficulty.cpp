#include "Difficulty.h"
#include "Game.h"
#include <iostream>

Difficulty::Difficulty(float width, float height)
{
	font.loadFromFile("resources/lunchds.ttf");

	title.setFont(font);
	title.setString("Poziom trudnosci:");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Latwy");
	menu[0].setPosition(sf::Vector2f(width / 2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Sredni");
	menu[1].setPosition(sf::Vector2f(width / 2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Trudny");
	menu[2].setPosition(sf::Vector2f(width / 2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Difficulty::~Difficulty()
{
}

void Difficulty::draw(sf::RenderWindow& window)
{
	window.draw(title);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}


void Difficulty::MouseMove(sf::Vector2i& mouse_pos)
{
	selectedItemIndex = -1;
	sf::Vector2f mouse_pos_translated = static_cast<sf::Vector2f>(mouse_pos);
	for (int i = 0; i <= 2; i++)
		menu[i].setFillColor(sf::Color::White);
	for (int i = 0; i <= 2; i++)
	{
		if (menu[i].getGlobalBounds().contains(mouse_pos_translated))
		{
			menu[i].setFillColor(sf::Color::Red);
			selectedItemIndex = i;
		}
	}
}

void Difficulty::DifficultyRun(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_pos)
{
	mouse_pos = sf::Mouse::getPosition(window);
	int diff = 0;
	Game game(window.getSize().x, window.getSize().y);

	while (window.pollEvent(event))
	{
		switch (event.type)
		{


		case sf::Event::Closed: //zamkni�cie okna za pomoc� 'x'
			window.close();
		case sf::Event::MouseMoved: //sprawdzanie ruchu mysz�
			this->MouseMove(mouse_pos);
			break;
		case sf::Event::MouseButtonPressed: //sprawdzanie czy przycisk myszy zosta� wci�ni�ty
			switch (this->GetPressedItem())
			{
			case 0:
				diff = 1;
				game.Update(window, diff);
				break;
			case 1:
				diff = 2;
				game.Update(window, diff);
				break;
			case 2:
				diff = 3;
				game.Update(window, diff);
				break;
			}
		}
	}
}
