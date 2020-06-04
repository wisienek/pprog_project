#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

#include "Menu.h"
#include "IEntity.h"
#include "Authors.h"
#include "Difficulty.h"
#include "main.h"
#include "PauseMenu.h"


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game"); //zdefiniowanie wielkości i nazwy okna
    Menu menu(window.getSize().x, window.getSize().y); //utowrzenie menu
    Authors authors(window.getSize().x, window.getSize().y); //utworzenie autorów
    Difficulty difficulty(window.getSize().x, window.getSize().y); //utworzenie poziomów trudności
    PauseMenu pausemenu(window.getSize().x, window.getSize().y);
    while (window.isOpen()) //pętla gry
    {
      
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window); //przypisywanie pozycji myszy do zmiennej
        sf::Event event; 
        
        menu.MenuRun(window, event, mouse_pos, authors); //uruchomienie menu
        //odświeżanie okna
        window.clear();
        menu.draw(window);
        window.display();
    }
    return 0;
}