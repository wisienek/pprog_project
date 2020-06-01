#include <SFML/Graphics.hpp>
#include <iostream>

#include "Menu.h"
#include "IEntity.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game");

    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            switch (event.type)
            {

            case sf::Event::Closed:
                window.close();

            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        std::cout << "Gra startuje" << std::endl;
                        window.clear();


                        break;
                    case 1:
                        std::cout << "Wczytywanie" << std::endl;
                        break;
                    case 2:
                        std::cout << "Wyniki" << std::endl;
                        break;
                    case 3:
                        std::cout << "Autorzy" << std::endl;
                        break;
                    case 4:
                        std::cout << "Wyjscie" << std::endl;
                        window.close();
                        break;
                    }
                }
            }
        }

        window.clear();
        menu.draw(window);
        window.display();
    }
    return 0;
}