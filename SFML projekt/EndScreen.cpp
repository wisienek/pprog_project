#include "EndScreen.h"
#include <iostream>

EndScreen::EndScreen(float width, float height)
{
	if (!font.loadFromFile("resources/lunchds.ttf")) //³adowanie czcionki i obs³uga b³êdu o jej braku
	{
		std::cout << "Brak czcionki" << std::endl;
	}

	logotexture.loadFromFile("resources/zsk.png"); //³adowanie tekstury dla logo
	logo.setTexture(logotexture); //ustawienie wybranej tekstury dla logo
	logo.setScale(0.5, 0.5); //ustawienie wielkoœci logo
	logo.setPosition(sf::Vector2f(100, 100)); //ustawienie pozycji logo

	option[0].setFont(font); //ustawienie czcionki dla tekstu w menu
	option[0].setFillColor(sf::Color::White); //ustawienie domyœlnego koloru tekstu
	option[0].setString("Wyjdz bez zapisywania"); //ustawienie linijki tekstu w menu
	option[0].setPosition(sf::Vector2f(960, 1000)); //ustawienie pozycji tekstu

	info[0].setFont(font); 
	info[0].setFillColor(sf::Color::White); 
	info[0].setString("Gratulacje, zdobyles "); 
	info[0].setPosition(sf::Vector2f(960,200));

	info[1].setFont(font);
	info[1].setFillColor(sf::Color::White);
	info[1].setString("Wpisz nick aby zapisac wynik");
	info[1].setPosition(sf::Vector2f(960,500));

	inputboxtexture.loadFromFile("resources/inputbox.png"); 
	inputbox.setTexture(inputboxtexture);
	inputbox.setScale(0.5, 0.5); 
	inputbox.setPosition(sf::Vector2f(960, 540));

	playerText.setFont(font);
	playerText.setFillColor(sf::Color::White);
	playerText.setString(playerInput);
	playerText.setPosition(sf::Vector2f(970, 545));


	selectedItemIndex = -1; //domyœlny indeks pozycji 
}

EndScreen::~EndScreen()
{
}

void EndScreen::draw(sf::RenderWindow& window)
{
	window.draw(logo);
	for (int i = 0; i < 2; i++)
	{
		window.draw(info[i]);
	}
	window.draw(inputbox);
	window.draw(option[0]);
	window.draw(playerText);

	
}

void EndScreen::MouseMove(sf::Vector2i& mouse_pos)
{
	selectedItemIndex = -1;
	sf::Vector2f mouse_pos_translated = static_cast<sf::Vector2f>(mouse_pos);
	option[0].setFillColor(sf::Color::White);
	if (option[0].getGlobalBounds().contains(mouse_pos_translated))
	{
		option[0].setFillColor(sf::Color::Red);
		selectedItemIndex = 1;
	}
	
}

void EndScreen::EndScreenRun(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_pos)
{
	while (window.pollEvent(event))
	{

		switch (event.type)
		{
		
		case sf::Event::Closed: //zamkniêcie okna za pomoc¹ 'x'
			window.close();
		case sf::Event::MouseMoved: //sprawdzanie ruchu mysz¹
			this->MouseMove(mouse_pos);
			break;
		case sf::Event::TextEntered:

			if (event.text.unicode == '\b' && playerInput.getSize() != 0)
			{
				playerInput.erase(playerInput.getSize() - 1, 1);
				playerText.setString(playerInput);
			}
			else if (playerInput.getSize() != 15)
			{
				playerInput += static_cast<char>(event.text.unicode);
				playerText.setString(playerInput);
			}
			break;
		case sf::Event::MouseButtonPressed: //sprawdzanie czy przycisk myszy zosta³ wciœniêty
			switch (event.key.code)
			{

				case sf::Mouse::Left: //sprawdzenie czy wciœniêtym przyciskiem by³ LPM
				{
					if (this->GetPressedItem()==1)
					{
						
						std::cout << "Wyjscie bez zapisu" << std::endl;
						break;
					}
				}
			}

			break;


		}
	}
}
