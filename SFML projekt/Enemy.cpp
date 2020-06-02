/*#include "Enemy.h"
#include "Bullet_b.h"


Enemy::Enemy( std::string type ){
	if (type == "Tank") {
		this->hp = 200;
		this->shape.setSize(sf::Vector2f(80.f, 80.f));
		this->mvspeed = 35.f;
		this->armour = 120;
		this->view = 35.f;
		this->b->setAttr(50,false,100);
		this->recoil = 6;
	}
	else if (type == "Sniper") {
		this->hp = 80;
		this->shape.setSize(sf::Vector2f(50.f, 50.f));
		this->mvspeed = 40.f;
		this->armour = 20;
		this->view = 60.f;
		this->b->setAttr(40, true, 130);
		this->recoil = 4;
	}
	else if (type == "Normal") {
		this->hp = 100;
		this->shape.setSize(sf::Vector2f(60.f, 60.f));
		this->mvspeed = 65.f;
		this->armour = 70;
		this->view = 25.f;
	}
	else{
		//minion
		this->hp = 20;
		this->shape.setSize(sf::Vector2f(40.f, 40.f));
		this->mvspeed = 65.f;
		this->armour = 5;
		this->view = 15.f;
		this->recoil = 5;
	}
}
Enemy::~Enemy() { delete this; }

void Enemy::shoot(IEntity* tower) {
	b -> render(); //Stwórz pocisk
	sf::Vector2f v = tower->getPos(); //Pobierz pozycje przeciwnika
	b->move(v.x, v.y); //Rusz pocisk na przeciwnika
}*/