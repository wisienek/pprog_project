#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Enemy.h"
#include "PauseMenu.h"

class Game
{
    sf::Font font;
    sf::Texture mapTexture;
    sf::Sprite map;
    sf::Time timer; // pokazuje ile min�o czasu w sekundach od startu meczu
    int points; // og�lne pkt wszystkie
    int roundPoints; //Max pkt za rund�
    int diff; //trudno��
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

public:
    Game(float width, float height);
    ~Game();
    void Update(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_pos, int _diff);

    void RoundRun(sf::RectangleShape& BaseHealth, int counter, sf::RenderWindow& window, sf::Clock& clock, sf::Time& timer, PauseMenu& pausemenu, sf::Vector2i& mouse_pos, sf::Text& goldtext, std::string& goldstring, sf::Text& timertext, std::string& timerstring, int& menuitem, sf::Sprite& map, sf::RectangleShape& startRect, sf::Text& start, int& gold, sf::Event& event);

};

