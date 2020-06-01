#include "IEntity.h"

IEntity::IEntity() {
	++count;
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->mvspeed = 100.f;
	this->armour = 100;
	this->hp = 100;
	this->id = count;
	this->view = 25.f;
}

IEntity::~IEntity() {
	delete this;
}

void IEntity::move(const float x, const float y) {
	this->shape.move(x * this->mvspeed, y * this->mvspeed);
}