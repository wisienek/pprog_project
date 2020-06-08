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
    start.setFont(font);
    start.setString("START");
    start.setPosition(0, 1040);
    startRect.setFillColor(sf::Color::Black);
    startRect.setSize(sf::Vector2f(105, 50));
    startRect.setPosition(0, 1040);
}
Game::~Game() 
{

}

void Game::Update(sf::RenderWindow& window , sf::Event& event, sf::Vector2i& mouse_pos, int _diff)
{
    mouse_pos = sf::Mouse::getPosition(window);
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
        window.draw(startRect);
        window.draw(start);
        window.display();
        while (window.pollEvent(event))
        {
            mouse_pos = sf::Mouse::getPosition(window);
            

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

void Game::RoundRun(int& counter, sf::RenderWindow& window, sf::Clock& clock, sf::Time& timer, PauseMenu& pausemenu, sf::Vector2i& mouse_pos, sf::Text& goldtext, std::string& goldstring, sf::Text& timertext, std::string& timerstring, int& menuitem, sf::Sprite& map, sf::RectangleShape& startRect, sf::Text& start, int& gold, sf::Event& event)
{
    Enemy* opponents = new Enemy[counter];
    bool closer = false;
    for (int i = 0; i < counter; i++)
    {
        if (closer == true)
        {
            opponents[i].spawn.x = 1064;
            opponents[i].spawn.y = 70;
            closer = false;
        }
        else
        {
            opponents[i].spawn.x = 1790;
            opponents[i].spawn.y = 180;
            closer = true;
        }
    }
    mouse_pos = sf::Mouse::getPosition(window);
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
        window.draw(startRect);
        window.draw(start);
        window.display();
        while (window.pollEvent(event))
        {
            mouse_pos = sf::Mouse::getPosition(window);


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
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
        for (int i = 0; i < counter; i++)
        {
            opponents[i].SpawnEnemy(window);
        }
        if (menuitem == 4)
            break;
    }
}