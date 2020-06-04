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

	void draw(sf::RenderWindow& window); //wyœwietlanie menu

	int GetPressedItem() { return selectedItemIndex; } //funkcja zwracaj¹ca indeks pozycji w menu

	void MouseMove(sf::Vector2i mouse_pos); //funkcja sprawdzaj¹ca po³o¿enie myszy i zmieniaj¹ca wygl¹d tekstu po najechaniu na niego

	void PauseMenuRun(sf::RenderWindow& window, sf::Event& event, sf::Vector2i mouse_pos);
private:
	sf::Text pausemenu[4]; //pozycje w menu
	sf::Text title;
	int selectedItemIndex; //indeks wybranej pozycji w menu
	sf::Font font; //czcionka dla menu
};

