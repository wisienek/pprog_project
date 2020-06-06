#include "Authors.h"
#include <iostream>


Authors::Authors(float width, float height)
{
	if (!font.loadFromFile("resources/lunchds.ttf"))
	{
		std::cout << "Brak czcionki" << std::endl;
	}

	authors[0].setFont(font);
	authors[0].setFillColor(sf::Color::White);
	authors[0].setString("Autorzy:");
	authors[0].setPosition(sf::Vector2f(width / 2.5, height / 6));

	authors[1].setFont(font);
	authors[1].setFillColor(sf::Color::White);
	authors[1].setString("Milosz Wisniewski");
	authors[1].setPosition(sf::Vector2f(width / 2.5, height / (6 + 1) * 2));

	authors[2].setFont(font);
	authors[2].setFillColor(sf::Color::White);
	authors[2].setString("Nikolas Szwargot");
	authors[2].setPosition(sf::Vector2f(width / 2.5, height / (6 + 1) * 3));

	authors[3].setFont(font);
	authors[3].setFillColor(sf::Color::White);
	authors[3].setString("Oskar Szymanski");
	authors[3].setPosition(sf::Vector2f(width / 2.5, height / (6 + 1) * 4));

	authors[4].setFont(font);
	authors[4].setFillColor(sf::Color::White);
	authors[4].setString("Adam Wandelt");
	authors[4].setPosition(sf::Vector2f(width / 2.5, height / (6 + 1) * 5));

	authors[5].setFont(font);
	authors[5].setCharacterSize(20);
	authors[5].setFillColor(sf::Color::White);
	authors[5].setString("'ESC' aby wrocic");
	authors[5].setPosition(sf::Vector2f(100,600));

}

Authors::~Authors()
{
}

void Authors::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(authors[i]);
	}
}

void Authors::AuthorsRun(sf::RenderWindow& window, sf::Event& event)
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed: //zamkniêcie okna za pomoc¹ 'x'
			window.close();
		}
	}
}
