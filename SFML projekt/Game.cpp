#include "Game.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"

Game::Game(float width, float height)
{
    mapTexture.loadFromFile("resources/mapkaprog.png");
    map.setTexture(mapTexture);
    map.setPosition(0, 0);
    points = 0;
}
Game::~Game() 
{

}

void Game::Update(sf::RenderWindow& window , int _diff)
{
    while (window.isOpen())
    {
        std::cout << "Dziala";
        window.clear();
        window.draw(map);
        window.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
    }
}