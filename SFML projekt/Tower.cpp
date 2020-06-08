#include "Tower.h"


Tower::Tower(std::string type) {
	this->team = 1;
	//do ka¿dego zmieñ sprity
	if (type == "Tank") {
		this->hp = 2;
		this->shape.setSize(sf::Vector2f(80.f, 80.f));
		this->mvspeed = -1;
		this->armour = 1;
		this->view = 35.f;
		this->b_dmg = 65;
		this->pen = false;
		this->recoil = 8;
	}
	else if (type == "Sniper") {
		this->hp = 80;
		this->shape.setSize(sf::Vector2f(50.f, 50.f));
		this->mvspeed = -1;
		this->armour = -1;
		this->view = 60;
		this->b_dmg = 45;
		this->pen = true;
		this->recoil = -1;
	}
	else if (type == "Base") {
		this->hp = 1000;
		this->shape.setSize(sf::Vector2f(100.f, 100.f));
		this->mvspeed = -1;
		this->armour = 400;
		this->view = -1;
		this->b_dmg = -1;
		this->pen = false;
		this->recoil = -1;
	}
	else {
		this->hp = 100;
		this->shape.setSize(sf::Vector2f(60.f, 60.f));
		this->mvspeed = -1;
		this->armour = -1;
		this->view = 25.f;
	}
}