#include "Difficulty.h"
#include <iostream>

Difficulty::Difficulty(float width, float height)
{
	font.loadFromFile("lunchds.ttf");

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
	while (window.pollEvent(event))
	{
		switch (event.type)
		{


		case sf::Event::Closed: //zamkniêcie okna za pomoc¹ 'x'
			window.close();
		case sf::Event::MouseMoved: //sprawdzanie ruchu mysz¹
			this->MouseMove(mouse_pos);
			break;
		case sf::Event::MouseButtonPressed: //sprawdzanie czy przycisk myszy zosta³ wciœniêty
			switch (this->GetPressedItem())
			{
			case 0:
				std::cout << "Latwy" << std::endl;
				break;
			case 1:
				std::cout << "Sredni" << std::endl;
				break;
			case 2:
				std::cout << "Trudny" << std::endl;
				break;
			}
		}
	}
}
