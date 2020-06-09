#include "Enemy.h"
#include "EndScreen.h"

Enemy::Enemy()
{
}

Enemy::Enemy( float x, float y) {
	spawn.x = x;
	spawn.y = y;
}
Enemy::~Enemy()
{ 
}

void Enemy::SpawnEnemy(sf::RenderWindow& window)
{
	this->sprite.setPosition(spawn.x, spawn.y);
	window.draw(sprite);
	window.display();

}

void Enemy::SetType(std::string type)
{
	this->team = 0;
	if (type == "Tank") {
		this->hp = 200;
		this->texture.loadFromFile("resources/enemies/3_ORK.png");
		this->sprite.setTexture(texture);
		this->mvspeed = 0.5;
		this->armour = 60;
		this->b_dmg = 40;
		this->pen = false;
	}
	else if (type == "Sniper") {
		this->hp = 80;
		this->texture.loadFromFile("resources/enemies/2_ORK.png");
		this->sprite.setTexture(texture);
		this->mvspeed = 1;
		this->armour = 20;
		this->b_dmg = 50;
		this->pen = false;
	}
	else {
		this->hp = 100;
		this->texture.loadFromFile("resources/enemies/1_ORK.png");
		this->sprite.setTexture(texture);
		this->mvspeed = 0.8;
		this->armour = 70;
		this->b_dmg = 20;
	}

	sprite.setScale(0.1f, 0.1f);
}

void Enemy::OppMove(sf::RenderWindow& window, sf::RectangleShape& BaseHealth, int& counter)
{
	if (hitted == false)
	{
		if (spawn.x == 839)
		{
			if (sprite.getPosition().x < 96)
			{
				if (sprite.getPosition().y > 825)
				{
					this->BaseHit(BaseHealth, counter);
				}
				sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + mvspeed);
			}
			else if (sprite.getPosition().y > 445)
			{
				sprite.setPosition(sprite.getPosition().x - mvspeed, sprite.getPosition().y);
			}
			else
			{
				sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + mvspeed);
			}
		}
		else
		{
			if (sprite.getPosition().x < 96)
			{
				if (sprite.getPosition().y > 825)
				{
					this->BaseHit(BaseHealth, counter);
				}
				else
				{
					sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + mvspeed);
				}
			}
			else if (sprite.getPosition().x < 1080)
			{
				if (sprite.getPosition().y < 455)
				{
					sprite.setPosition(sprite.getPosition().x - mvspeed, sprite.getPosition().y);
				}
				else
				{
					sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - mvspeed);
				}
			}
			else if (sprite.getPosition().y > 920)
			{
				sprite.setPosition(sprite.getPosition().x - mvspeed, sprite.getPosition().y);
			}
			else
			{
				sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + mvspeed);
			}
		}
		window.draw(sprite);
	}
}

void Enemy::BaseHit(sf::RectangleShape& BaseHealth, int& counter)
{
	BaseHealth.setSize(sf::Vector2f(BaseHealth.getSize().x - b_dmg, BaseHealth.getSize().y));
	this->hitted = true;
	counter--;
}