#pragma once
#include "IEntity.h"

class Enemy : public IEntity {
public:

	Enemy( std::string type );
	~Enemy();


	void shoot(IEntity& player);
};