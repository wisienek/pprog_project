#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet_b.h"

static int count = 0;

class IEntity
{
protected:
	int id; //Identyfikator 
	int hp; //Ile ma ¿ycia
	int armour; //Ile ma pancerza
	float mvspeed; //Jak szybko siê porusza
	float view; //Jaki ma zasiêg widzenia
	int recoil; //Co ile sekund mo¿e strzelaæ
	sf::RectangleShape shape;

	Bullet_b *b;

public:
	IEntity();
	virtual ~IEntity();

	int getId() {
		return id;
	}

	sf::Vector2f getPos() {
		return shape.getPosition();
	}

	//Renderuj i poruszaj
	void move(const float x, const float y);
	virtual void render(sf::RenderTarget& target) = 0;
	virtual void shoot(IEntity* tower) = 0;

};

