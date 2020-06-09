#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Enemy.h"
#include "PauseMenu.h"

class Game
{
    int maxtowers = 30;
    sf::Font font;
    sf::Texture mapTexture;
    sf::Sprite map;
    sf::Time timer; // pokazuje ile minê³o czasu w sekundach od startu meczu
    int points; // ogólne pkt wszystkie
    int roundPoints; //Max pkt za rundê
    int diff; //trudnoœæ
    int gold;
    float pointsconverter;
    sf::Text goldtext;
    std::string goldstring;
    sf::Text timertext;
    std::string timerstring;
    sf::Text start;
    sf::RectangleShape startRect;
    int roundscounter;
    sf::Text roundText;
    sf::Texture towers[3];
    sf::Sprite towersSprite[3];
    sf::Text shopText;
    sf::Text prizes;

public:
    Game(float width, float height);
    ~Game();
    int Update(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_pos, int _diff);

    int RoundRun(sf::RectangleShape& BaseHealth, int counter, sf::RenderWindow& window, sf::Clock& clock, sf::Time& timer, PauseMenu& pausemenu, sf::Vector2i& mouse_pos, sf::Text& goldtext, std::string& goldstring, sf::Text& timertext, std::string& timerstring, int& menuitem, sf::Sprite& map, sf::RectangleShape& startRect, sf::Text& start, int& gold, sf::Event& event);

};

