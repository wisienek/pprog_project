#pragma once
#include "IEntity.h"
#include "Bullet_b.h"

class EBullet : public Bullet_b {
	//za�aduj kszta�t i obrazek
	
	void render();
	void update();
};

class Enemy : public IEntity {
public:

	Enemy( std::string type );
	~Enemy();

	void shoot(IEntity* tower);
	
};