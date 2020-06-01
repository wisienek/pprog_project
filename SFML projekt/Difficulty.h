#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Menu.h"
#define MAX_NUMBER_OF_ITEMS 6

class Difficulty
	:public Menu
{
public:

	Difficulty(float width, float height);

	~Difficulty();
	void draw(sf::RenderWindow& window);

	void MoveDown();

private:
	sf::Text title;
	sf::Text menu[3];
};