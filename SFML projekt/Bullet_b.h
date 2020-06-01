#pragma once
#include <SFML/Graphics.hpp>

class Bullet_b
{
protected:
	int power; //Ile ma pobieraæ z hp/armora
	bool penetrating; //Czy ma omijaæ armor
	float mvspeed; //Jak szybko siê porusza

	sf::RectangleShape shape;

public:
	Bullet_b();
	~Bullet_b();


	virtual void update() = 0;
	virtual void move(const float x, const float y) = 0;

};

