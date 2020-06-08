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
	this->t_recoil = 0;
	this->b_dmg = 30;
	this->pen = false;
}

IEntity::~IEntity() {
	delete this;
}

void IEntity::render(const float x, const float y) {
	shape.setPosition(x, y);
}

void IEntity::move(const float x, const float y) {
	shape.move(x * this->mvspeed, y * this->mvspeed);
}

void IEntity::update() {
	//Zrób update txt pod wie¿¹: hp i armour
}

void IEntity::damage(IEntity& tower) {
	if (this->pen == true) {
		tower.setHp(tower.getHp() - this->b_dmg);
		//tower.update();
		return;
	}
	int t_arm = tower.getAr();
	if (t_arm - this->b_dmg < 0) {
		tower.setAr(0);
		t_arm = this->b_dmg - t_arm;
		if (tower.getHp() - t_arm < 0) {
			delete& tower;
		}
		else {
			tower.setHp(tower.getHp() - t_arm);
		}
		return;
	}
	tower.setAr(t_arm - b_dmg);
	return;
}