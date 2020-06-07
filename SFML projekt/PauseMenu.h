#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"

class PauseMenu
{
public:
	//konstruktory
	PauseMenu();
	PauseMenu(float width, float height);

	~PauseMenu(); //destruktor

	void draw(sf::RenderWindow& window); //wy�wietlanie menu

	int GetPressedItem() { return selectedItemIndex; } //funkcja zwracaj�ca indeks pozycji w menu

	void MouseMove(sf::Vector2i& mouse_pos); //funkcja sprawdzaj�ca po�o�enie myszy i zmieniaj�ca wygl�d tekstu po najechaniu na niego

	int PauseMenuRun(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_pos);
private:
	sf::Texture bgtexture;
	sf::Sprite bg;
	sf::Text pausemenu[4]; //pozycje w menu
	sf::Text title;
	int selectedItemIndex; //indeks wybranej pozycji w menu
	sf::Font font; //czcionka dla menu
};

