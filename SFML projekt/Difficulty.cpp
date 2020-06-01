#include "Difficulty.h"
#include <iostream>


Difficulty::Difficulty(float width, float height)
{
	title.setFont(font);
	title.setString("Poziom trudnosci:");
	title.setPosition(sf::Vector2f(width / 2.5, height / (3 + 1) * 1));

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Latwy");
	menu[0].setPosition(sf::Vector2f(width / 2.5, height / (3 + 1) * 2));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Sredni");
	menu[1].setPosition(sf::Vector2f(width / 2.5, height / (3 + 1) * 3));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Trudny");
	menu[2].setPosition(sf::Vector2f(width / 2.5, height / (3 + 1) * 4));
}

void Difficulty::draw(sf::RenderWindow& window)
{
	window.draw(title);
	for (int i = 0; i < 3; i++)
	{
		window.draw(menu[i]);
	}
}

void Difficulty::MoveDown()
{
	if (selectedItemIndex + 1 < 3)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}