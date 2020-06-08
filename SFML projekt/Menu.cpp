#include "Menu.h"
#include <iostream>


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("resources/lunchds.ttf")) //³adowanie czcionki i obs³uga b³êdu o jej braku
	{
		std::cout << "Brak czcionki" << std::endl;
	}

	logotexture.loadFromFile("resources/zsk.png"); //³adowanie tekstury dla logo
	logo.setTexture(logotexture); //ustawienie wybranej tekstury dla logo
	logo.setScale(0.5, 0.5); //ustawienie wielkoœci logo
	logo.setPosition(sf::Vector2f(100,100)); //ustawienie pozycji logo

	menu[0].setFont(font); //ustawienie czcionki dla tekstu w menu
	menu[0].setFillColor(sf::Color::Red); //ustawienie domyœlnego koloru tekstu
	menu[0].setString("Start gry"); //ustawienie linijki tekstu w menu
	menu[0].setPosition(sf::Vector2f(width/2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1)); //ustawienie pozycji tekstu

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Wczytaj gre");
	menu[1].setPosition(sf::Vector2f(width/2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("TOP score");
	menu[2].setPosition(sf::Vector2f(width/2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Opcje");
	menu[3].setPosition(sf::Vector2f(width/2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("Autorzy");
	menu[4].setPosition(sf::Vector2f(width / 2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

	menu[5].setFont(font);
	menu[5].setFillColor(sf::Color::White);
	menu[5].setString("Wyjscie");
	menu[5].setPosition(sf::Vector2f(width/2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 6));

	selectedItemIndex = 0; //domyœlny indeks pozycji 
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window) 
{
	window.draw(logo);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MouseMove(sf::Vector2i& mouse_pos)
{
	selectedItemIndex = -1;
	sf::Vector2f mouse_pos_translated = static_cast<sf::Vector2f>(mouse_pos);
	for (int i = 0; i <= 5; i++)
		menu[i].setFillColor(sf::Color::White);
	for (int i = 0; i <= 5; i++)
	{
		if (menu[i].getGlobalBounds().contains(mouse_pos_translated))
		{
			menu[i].setFillColor(sf::Color::Red);
			selectedItemIndex = i;
		}
	}

}

void Menu::MenuRun(sf::RenderWindow& window,sf::Event& event, sf::Vector2i& mouse_pos, Authors& authors, Difficulty& difficulty
)
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
        case sf::Event::MouseButtonPressed: //sprawdzanie czy przycisk myszy zosta³ wciœniêty
            switch (event.key.code)
            {

            case sf::Mouse::Left: //sprawdzenie czy wciœniêtym przyciskiem by³ LPM
            
                switch (this->GetPressedItem())
                {
                case 0:
                    std::cout << "Gra startuje" << std::endl;
					while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						window.clear();
						difficulty.draw(window);
						window.display();
						difficulty.DifficultyRun(window, event, mouse_pos);
					}
                    break;
                case 1:
                    std::cout << "Wczytywanie" << std::endl;
					
					break;
                case 2:
                    std::cout << "Wyniki" << std::endl;
                    break;
                case 3:
                    std::cout << "Opcje" << std::endl;
                    break;
                case 4:
                    std::cout << "Autorzy" << std::endl;
					while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						window.clear();
						authors.draw(window);
						window.display();
						authors.AuthorsRun(window, event);
					}
					break;
                case 5:
                    std::cout << "Wyjscie" << std::endl; //opcja wyjœcia z programu w menu
                    window.close();
                    break;
                }
            }
            break;

        
        }
    }
}
