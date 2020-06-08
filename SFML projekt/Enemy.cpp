#include "Enemy.h"


Enemy::Enemy( std::string type ){
	this->team = 0;
	//do ka¿dego zmieñ sprity
	if (type == "Tank") {
		this->hp = 200;
		this->shape.setSize(sf::Vector2f(80.f, 80.f));
		//this->shape.setTexture(loadFromFile("resources/3_ORK.png"));
		this->mvspeed = 35.f;
		this->armour = 120;
		this->b_dmg = 40;
		this->pen = false;
	}
	else if (type == "Sniper") {
		this->hp = 80;
		this->shape.setSize(sf::Vector2f(50.f, 50.f));
		//this->shape.setTexture(loadFromFile("resources/2_ORK.png"));
		this->mvspeed = 40.f;
		this->armour = 20;
		this->b_dmg = 50;
		this->pen = false;
	}
	else {
		this->hp = 100;
		this->shape.setSize(sf::Vector2f(60.f, 60.f));
		//this->shape.setTexture(loadFromFile("resources/1_ORK.png"));
		this->mvspeed = 65.f;
		this->armour = 70;
	}
}
Enemy::~Enemy() { delete this; }