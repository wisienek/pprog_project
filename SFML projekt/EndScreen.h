#pragma once
#pragma once
#include "Authors.h"
#include "Difficulty.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#define MAX_NUMBER_OF_ITEMS 1
class EndScreen
{
public:
	//konstruktory
	EndScreen();
	EndScreen(float width, float height);

	~EndScreen(); //destruktor

	void draw(sf::RenderWindow& window); //wyœwietlanie menu

	int GetPressedItem() { return selectedItemIndex; } //funkcja zwracaj¹ca indeks pozycji w menu

	void MouseMove(sf::Vector2i& mouse_pos); //funkcja sprawdzaj¹ca po³o¿enie myszy i zmieniaj¹ca wygl¹d tekstu po najechaniu na niego
	int EndScreenRun(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_pos);

private:
	sf::Text option[MAX_NUMBER_OF_ITEMS]; //pozycje w menu
	sf::Text info[2];

	sf::Texture logotexture; //tekstura logo
	sf::Sprite logo;
	sf::Texture inputboxtexture; //tekstura logo
	sf::Sprite inputbox;

	int selectedItemIndex; //indeks wybranej pozycji w menu

	sf::Font font; //czcionka dla menu

	sf::String playerInput; //string do wpisywania
	sf::Text playerText; //tekst do wyœwietlenia
};

