#pragma once
#include "Authors.h"
#include "Difficulty.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#define MAX_NUMBER_OF_ITEMS 6
class Menu
{
public:
	//konstruktory
	Menu();
	Menu(float width, float height);

	~Menu(); //destruktor

	void draw(sf::RenderWindow& window); //wyœwietlanie menu

	int GetPressedItem() { return selectedItemIndex; } //funkcja zwracaj¹ca indeks pozycji w menu

	void MouseMove(sf::Vector2i& mouse_pos); //funkcja sprawdzaj¹ca po³o¿enie myszy i zmieniaj¹ca wygl¹d tekstu po najechaniu na niego
	void MenuRun(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_pos, Authors& authors, Difficulty& difficulty);

private:
	sf::Text menu[MAX_NUMBER_OF_ITEMS]; //pozycje w menu
	sf::Texture logotexture; //tekstura logo
	sf::Sprite logo; 
	int selectedItemIndex; //indeks wybranej pozycji w menu
	sf::Font font; //czcionka dla menu
};

