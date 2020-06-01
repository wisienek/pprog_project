#pragma once
#include <SFML/Graphics.hpp>

class Bullet_b
{
protected:
	int power;
	bool penetrating;
	float mvspeed;

	sf::RectangleShape shape;

public:
	Bullet_b();
	~Bullet_b();


	virtual void update() = 0;
	virtual void move(const float x, const float y) = 0;

};

