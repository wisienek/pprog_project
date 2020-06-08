#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Enemy.h"

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

public:
    Game(float width, float height);
    ~Game();
    void Update(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_pos, int _diff);

};

