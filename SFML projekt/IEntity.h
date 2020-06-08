/*#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet_b.h"

static int count = 0;

class IEntity
{
protected:
	int id; //Identyfikator 
	int hp; //Ile ma �ycia
	int armour; //Ile ma pancerza
	float mvspeed; //Jak szybko si� porusza
	float view; //Jaki ma zasi�g widzenia
	int recoil; //Co ile sekund mo�e strzela�
	sf::RectangleShape shape;
	Bullet_b* b;

public:

	IEntity();
	~IEntity();

	int getId() {
		return id;
	}

	sf::Vector2f getPos() {
		return shape.getPosition();
	}

	//Renderuj i poruszaj
	void move(const float x, const float y);
	void render(sf::RenderTarget& target);
	void shoot(IEntity* tower);

};

<<<<<<< HEAD
<<<<<<< HEAD
=======
*/
>>>>>>> parent of f059e46... wieże
=======
*/
>>>>>>> parent of f059e46... wieże
