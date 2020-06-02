#pragma once
#include "Authors.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#define MAX_NUMBER_OF_ITEMS 6
class Menu
{
public:

	Menu();
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int GetPressedItem() { return selectedItemIndex; }
	void MouseMove(sf::Vector2i mouse_pos);
	void MenuRun(sf::RenderWindow& window, sf::Event& event, sf::Vector2i mouse_pos, Authors& authors);

private:
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Texture logotexture;
	sf::Sprite logo;
	int selectedItemIndex;
	sf::Font font;
};

