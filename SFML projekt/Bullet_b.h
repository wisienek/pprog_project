#pragma once
#include <SFML/Graphics.hpp>
#include "IEntity.h"

class Bullet_b
{
protected:
	int power; //Ile ma pobiera� z hp/armora
	bool penetrating; //Czy ma omija� armor
	float mvspeed; //Jak szybko si� porusza
	
	//IEntity* parent; //Kogo to pocisk
	sf::RectangleShape shape; //Kszta�t pocisku

public:
	Bullet_b();
	~Bullet_b();

	//ustaw w�a�ciwo�ci pocisku
	void setAttr(int _pow, bool _pen, float _mvsp) {
		power = _pow;
		penetrating = _pen;
		mvspeed = _mvsp;
	}

	 void render(); //renderuj przy starcie
	 void update(); //Co sekund�/tick r�b co� 
	void move(const float x, const float y); //Poruszaj
};

