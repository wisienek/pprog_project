#pragma once
class Bullet_b
{
	int power;
	bool penetrating;
	float speed;


public:
	Bullet_b();
	~Bullet_b();


	virtual void update() = 0;
	virtual void move(const float x, const float y) = 0;

};

