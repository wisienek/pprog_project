#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

static int count = 0;

class IEntity
{
protected:
	int id;
	int hp;
	int armour;
	float mvspeed;
	float view;

	sf::RectangleShape shape;


public:
	IEntity();
	virtual ~IEntity();

	int getId() {
		return id;
	}

	virtual void move(const float x, const float y) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
	

};

