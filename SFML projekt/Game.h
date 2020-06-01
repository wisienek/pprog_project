#pragma once

class Game
{
    int timer = 0; // pokazuje ile minê³o czasu w sekundach od startu meczu
    int points; // ogólne pkt wszystkie
    int roundPoints; //Max pkt za rundê
    int diff; //trudnoœæ

public:
    Game();
    ~Game();
    void Update();

};

