#include "PauseMenu.h"
#include <iostream>

PauseMenu::PauseMenu(float width, float height)
{
	if (!font.loadFromFile("lunchds.ttf")) //³adowanie czcionki i obs³uga b³êdu o jej braku
	{
		std::cout << "Brak czcionki" << std::endl;
	}
	title.setFont(font);
	title.setFillColor(sf::Color::White);
	title.setString("PAUZA");
	title.setPosition(sf::Vector2f(width / 2.5, height / (4 + 1) * 0.5));

	pausemenu[0].setFont(font); //ustawienie czcionki dla tekstu w menu
	pausemenu[0].setFillColor(sf::Color::Red); //ustawienie domyœlnego koloru tekstu
	pausemenu[0].setString("Wznow"); //ustawienie linijki tekstu w menu
	pausemenu[0].setPosition(sf::Vector2f(width / 2.5, height / (4 + 1))); //ustawienie pozycji tekstu

	pausemenu[1].setFont(font);
	pausemenu[1].setFillColor(sf::Color::White);
	pausemenu[1].setString("Zapisz gre");
	pausemenu[1].setPosition(sf::Vector2f(width / 2.5, height / (4 + 1)*1.25));

	pausemenu[2].setFont(font);
	pausemenu[2].setFillColor(sf::Color::White);
	pausemenu[2].setString("Restart");
	pausemenu[2].setPosition(sf::Vector2f(width / 2.5, height / (4 + 1)*1.50));

	pausemenu[3].setFont(font);
	pausemenu[3].setFillColor(sf::Color::White);
	pausemenu[3].setString("Wyjdz");
	pausemenu[3].setPosition(sf::Vector2f(width / 2.5, height / (4 + 1)*1.75));

	selectedItemIndex = 0; //domyœlny indeks pozycji 
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::draw(sf::RenderWindow& window)
{
	window.draw(title);
	for (int i = 0; i < 4; i++)
	{
		window.draw(pausemenu[i]);
	}
}

void PauseMenu::MouseMove(sf::Vector2i& mouse_pos)
{
	selectedItemIndex = -1;
	sf::Vector2f mouse_pos_translated = static_cast<sf::Vector2f>(mouse_pos);
	for (int i = 0; i < 4; i++)
		pausemenu[i].setFillColor(sf::Color::White);
	for (int i = 0; i < 4; i++)
	{
		if (pausemenu[i].getGlobalBounds().contains(mouse_pos_translated))
		{
			pausemenu[i].setFillColor(sf::Color::Red);
			selectedItemIndex = i;
		}
	}
}

void PauseMenu::PauseMenuRun(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_pos)
{
	while (window.pollEvent(event))
	{

		switch (event.type)
		{

		case sf::Event::Closed: //zamkniêcie okna za pomoc¹ 'x'
			window.close();
		case sf::Event::MouseMoved: //sprawdzanie ruchu mysz¹
			this->MouseMove(mouse_pos);
		case sf::Event::MouseButtonPressed: //sprawdzanie czy przycisk myszy zosta³ wciœniêty
			switch (event.key.code)
			{

			case sf::Mouse::Left: //sprawdzenie czy wciœniêtym przyciskiem by³ LPM

				switch (this->GetPressedItem())
				{
				case 0:
					std::cout << "Wznawianie" << std::endl;
					break;
				case 1:
					std::cout << "Zapisywanie" << std::endl;
					break;
				case 2:
					std::cout << "Restart" << std::endl;
					break;
				case 3:
					std::cout << "Wyjscie" << std::endl;
					break;
				}
			}
			break;
		}

	}
}
