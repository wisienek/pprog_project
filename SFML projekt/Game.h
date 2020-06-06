#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Game
{
    sf::Texture mapTexture;
    sf::Sprite map;
    sf::Time timer; // pokazuje ile minê³o czasu w sekundach od startu meczu
    int points; // ogólne pkt wszystkie
    int roundPoints; //Max pkt za rundê
    int diff; //trudnoœæ
    int gold;

public:
    Game(float width, float height);
    ~Game();
    void Update(sf::RenderWindow& window, int _diff);

};

