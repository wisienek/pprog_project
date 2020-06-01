#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

static int count = 0;

class IEntity
{
protected:
	int id; //Identyfikator 
	int hp; //Ile ma ¿ycia
	int armour; //Ile ma pancerza
	float mvspeed; //Jak szybko siê porusza
	float view; //Jaki ma zasiêg widzenia

	sf::RectangleShape shape;

public:
	IEntity();
	virtual ~IEntity();

	int getId() {
		return id;
	}

	//Renderuj i poruszaj
	virtual void move(const float x, const float y) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
	

};

