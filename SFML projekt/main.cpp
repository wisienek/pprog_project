#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

#include "Menu.h"
#include "IEntity.h"
#include "Authors.h"
#include "Difficulty.h"
#include "main.h"


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game");
    Menu menu(window.getSize().x, window.getSize().y);
    Authors authors(window.getSize().x, window.getSize().y);
    Difficulty difficulty(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {

        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Event event;
        menu.MenuRun(window,event,mouse_pos,authors);
        
        window.clear();
        menu.draw(window);
        window.display();
    }
    return 0;
}