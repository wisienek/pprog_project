﻿#include "Enemy.h"


Enemy::Enemy()
{
}

Enemy::Enemy(std::string type, float x, float y) {
	this->team = 0;
	if (type == "Tank") {
		this->hp = 200;
		this->texture.loadFromFile("resources/enemies/3_ORK.png");
		this->sprite.setTexture(texture);
		this->mvspeed = 35.f;
		this->armour = 120;
		this->b_dmg = 40;
		this->pen = false;
	}
	else if (type == "Sniper") {
		this->hp = 80;
		this->texture.loadFromFile("resources/enemies/2_ORK.png");
		this->sprite.setTexture(texture);
		this->mvspeed = 40.f;
		this->armour = 20;
		this->b_dmg = 50;
		this->pen = false;
	}
	else {
		this->hp = 100;
		this->texture.loadFromFile("resources/enemies/1_ORK.png");
		this->sprite.setTexture(texture);
		this->mvspeed = 65.f;
		this->armour = 70;
	}
	spawn.x = x;
	spawn.y = y;
}
Enemy::~Enemy() { delete this; }

void Enemy::SpawnEnemy(sf::RenderWindow& window)
{
	this->sprite.setPosition(spawn.x, spawn.y);
	window.draw(sprite);
	window.display();
}