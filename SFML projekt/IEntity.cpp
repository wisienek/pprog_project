#include "IEntity.h"

IEntity::IEntity() {
	++count;
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->mvspeed = 70.f;
	this->armour = 30;
	this->hp = 100;
	this->id = count;
	this->view = 55.f;
	this->recoil = 3;
	this->b = nullptr;
}

IEntity::~IEntity() {
	delete this;
}

void IEntity::move(const float x, const float y) {
	this->shape.move(x * this->mvspeed, y * this->mvspeed);
}