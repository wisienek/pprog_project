#pragma once
#include "IEntity.h"
#include "SpawnPoint.h"

class Enemy : public IEntity {
public:
	bool hitted = false;
	SpawnPoint spawn;
	Enemy();
	Enemy( float x, float y);
	~Enemy();

	void SpawnEnemy(sf::RenderWindow& window);
	void SetType(std::string type);

	void OppMove(sf::RenderWindow& window, sf::RectangleShape& BaseHealth, int& counter);

	void BaseHit(sf::RectangleShape& BaseHealth, int& counter);

};