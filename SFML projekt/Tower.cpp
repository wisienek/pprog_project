#include "Tower.h"


Tower::Tower(std::string type) {
	this->team = 1;
	if (type == "Tank") {
		this->texture.loadFromFile("resources/towers/1_tower.png");
		this->sprite.setTexture(texture);
		this->view = 35.f;
		this->b_dmg = 65;
		this->pen = false;
		this->recoil = 8;
	}
	else if (type == "Sniper") {
		this->texture.loadFromFile("resources/towers/1_tower.png");
		this->sprite.setTexture(texture);
		this->view = 60.f;
		this->b_dmg = 45;
		this->pen = true;
		this->recoil = 1;
	}
	else {
		this->texture.loadFromFile("resources/towers/1_tower.png");
		this->sprite.setTexture(texture);
		this->view = 25.f;
		this->b_dmg = 20;
		this->recoil = 5;
	}
}

Tower::~Tower()
{
}

void Tower::TowerBuild()
{

}
