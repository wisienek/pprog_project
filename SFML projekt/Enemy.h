#pragma once
#include "IEntity.h"
#include "SpawnPoint.h"

class Enemy : public IEntity {
public:
	SpawnPoint spawn;
	Enemy();
	Enemy(std::string type, float x, float y);
	~Enemy();

	void SpawnEnemy(sf::RenderWindow& window);

};