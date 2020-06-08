#pragma once
#include "IEntity.h"
#include "SpawnPoint.h"

class Enemy : public IEntity {
public:
	SpawnPoint spawn;
	Enemy();
	Enemy( float x, float y);
	~Enemy();

	void SpawnEnemy(sf::RenderWindow& window);
	void SetType(std::string type);

};