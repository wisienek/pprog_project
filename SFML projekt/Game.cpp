#include "Game.h"
#include <iostream>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "PauseMenu.h"
#include <Windows.h>
#include "EndScreen.h"

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
    roundscounter = 0;
    roundText.setFont(font);
}
Game::~Game() 
{

}

void Game::Update(sf::RenderWindow& window , sf::Event& event, sf::Vector2i& mouse_pos, int _diff)
{
    sf::RectangleShape BaseHealth;
    BaseHealth.setFillColor(sf::Color::Green);
    BaseHealth.setSize(sf::Vector2f(500, 25));
    BaseHealth.setScale(0.5, 1);
    BaseHealth.setPosition(105, 1047);
    int counter = 0;
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
        roundText.setString("Runda: " + std::to_string(roundscounter));
        roundText.setPosition(1404, 10);
        window.clear();
        window.draw(map);
        window.draw(timertext);
        window.draw(goldtext);
        window.draw(startRect);
        window.draw(BaseHealth);
        window.draw(start);
        window.draw(roundText);
        window.display();
        while (window.pollEvent(event))
        {
            mouse_pos = sf::Mouse::getPosition(window);
            sf::Vector2f mouse_pos_translated = static_cast<sf::Vector2f>(mouse_pos);
            if (startRect.getGlobalBounds().contains(mouse_pos_translated) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {

                counter += 5;
                RoundRun(BaseHealth, counter, window, clock, timer, pausemenu, mouse_pos, goldtext, goldstring, timertext, timerstring, menuitem, map, startRect, start, gold, event);
                          
            }
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

void Game::RoundRun(sf::RectangleShape& BaseHealth, int counter, sf::RenderWindow& window, sf::Clock& clock, sf::Time& timer, PauseMenu& pausemenu, sf::Vector2i& mouse_pos, sf::Text& goldtext, std::string& goldstring, sf::Text& timertext, std::string& timerstring, int& menuitem, sf::Sprite& map, sf::RectangleShape& startRect, sf::Text& start, int& gold, sf::Event& event)
{
    roundscounter++;
    Enemy* opponents = new Enemy[counter];
    bool closer = false;
    int spawnedoppcounter = 0;
    for (int i = 0; i < counter; i++)
    {
        if (closer == true)
        {
            opponents[i].spawn.x = 839;
            opponents[i].spawn.y = 70;
            closer = false;
        }
        else
        {
            opponents[i].spawn.x = 1711;
            opponents[i].spawn.y = 62;
            closer = true;
        }
    }
    for (int i = 0; i < counter; i++)
    {
        if (i % 15 == 0 && i != 0)
        {
            opponents[i].SetType("Sniper");
        }
        else if (i % 5 == 0)
        {
            opponents[i].SetType("Tank");
        }
        else
        {
            opponents[i].SetType("Normal");
        }
    }
    mouse_pos = sf::Mouse::getPosition(window);
    int framecounter = 120;
    while (window.isOpen())
    {
        framecounter--;
        timer = clock.getElapsedTime();
        goldstring = ("Zloto: " + std::to_string(gold));
        goldtext.setString(goldstring);
        timerstring = ("Czas: " + std::to_string(int(std::floor(timer.asSeconds()))));
        timertext.setString(timerstring);
        roundText.setString("Runda: " + std::to_string(roundscounter));
        roundText.setPosition(1404, 10);
        window.clear();
        window.draw(map);
        for (int i = 0; i < spawnedoppcounter; i++)
        {
            opponents[i].OppMove(window, BaseHealth, counter);
        }
        window.draw(timertext);
        window.draw(goldtext);
        window.draw(startRect);
        window.draw(start);
        window.draw(BaseHealth);
        window.draw(roundText);
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
        if (menuitem == 4)
            break;

        if (spawnedoppcounter < counter && framecounter == 0)
        {
            opponents[spawnedoppcounter].SpawnEnemy(window);
            spawnedoppcounter++;
            framecounter = 120;
        }
        timer = clock.getElapsedTime();
        goldstring = ("Zloto: " + std::to_string(gold));
        goldtext.setString(goldstring);
        timerstring = ("Czas: " + std::to_string(int(std::floor(timer.asSeconds()))));
        timertext.setString(timerstring);
        window.clear();
        window.draw(map);
        for (int i = 0; i < spawnedoppcounter; i++)
        {
            opponents[i].OppMove(window, BaseHealth, counter);
        }
        window.draw(timertext);
        window.draw(goldtext);
        window.draw(startRect);
        window.draw(start);
        window.draw(BaseHealth);
        window.draw(roundText);
        window.display();
        while (BaseHealth.getSize().x <= 0)
        {
            window.clear();
            EndScreen gameover(window.getSize().x, window.getSize().y);
            gameover.draw(window);
            window.display();
            gameover.EndScreenRun(window, event, mouse_pos);
        }

        if (counter == 0)
        {
            for (int i = 0; i < spawnedoppcounter; i++)
                opponents[i].~Enemy();
            delete[] opponents;
            break;
        }
    }
}