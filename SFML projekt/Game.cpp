#include "Game.h"
#include <iostream>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "PauseMenu.h"

Game::Game(float width, float height)
{
    mapTexture.loadFromFile("resources/mapkaprog.png");
    map.setTexture(mapTexture);
    map.setPosition(0, 0);
    points = 0;
    font.loadFromFile("resources/lunchds.ttf");
    goldtext.setFont(font);
    timertext.setFont(font);
    timertext.setPosition(0, 0);
    goldtext.setPosition(1700, 1040);
}
Game::~Game() 
{

}

void Game::Update(sf::RenderWindow& window , sf::Event& event, sf::Vector2i& mouse_pos, int _diff)
{
    this->diff = _diff;
    switch (diff)
    {
    case 1:
        gold = 3000;
        roundPoints = 500;
        pointsconverter = 1.0;
        break;
    case 2:
        gold = 3000;
        roundPoints = 750;
        pointsconverter = 1.5;
        break;
    case 3:
        gold = 2000;
        roundPoints = 1000;
        pointsconverter = 2;
        break;
    }
    int menuitem = -1;
    sf::Clock clock;
    mouse_pos = sf::Mouse::getPosition(window);
    PauseMenu pausemenu(window.getSize().x, window.getSize().y);
    while (window.isOpen())
    {
        timer = clock.getElapsedTime();
        goldstring = ("Zloto: " + std::to_string(gold));
        goldtext.setString(goldstring);
        timerstring = ("Czas: " + std::to_string(int(std::floor(timer.asSeconds()))));
        timertext.setString(timerstring);
        window.clear();
        window.draw(map);
        window.draw(timertext);
        window.draw(goldtext);
        window.display();
        while (window.pollEvent(event))
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                while (window.isOpen())
                {
                    menuitem = pausemenu.PauseMenuRun(window, event, mouse_pos);
                    if (menuitem != 0)
                    {
                        break;
                    }
                }
            }
            
        }
        if (menuitem == 4)
            break;
    }
}