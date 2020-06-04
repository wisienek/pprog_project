#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#define MAX_NUMBER_OF_ITEMS 3

class Difficulty
{
public:

	Difficulty();
	Difficulty(float width, float height);
	~Difficulty();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int GetPressedItem() { return selectedItemIndex; }
	void MouseMove(sf::Vector2i& mouse_pos);

	void DifficultyRun(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_pos);

private:
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Text title;
	int selectedItemIndex;
	sf::Font font;
};