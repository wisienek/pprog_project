#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#define MAX_NUMBER_OF_ITEMS 6

class Authors
{
public:
	Authors(float width, float height);
	~Authors();

	void draw(sf::RenderWindow& window);


private:
	sf::Font font;
	sf::Text authors[MAX_NUMBER_OF_ITEMS];


};

