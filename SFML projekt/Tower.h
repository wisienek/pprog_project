#pragma once
#include "IEntity.h"
class Tower : public IEntity
{
	sf::Texture texture;
	sf::Sprite sprite;
	Tower(std::string type);
	~Tower();

	void TowerBuild();

};