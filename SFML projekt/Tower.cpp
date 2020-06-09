#include "Tower.h"
#include <math.h>

Tower::Tower()
{
}

void Tower::SetType(std::string type) {
	this->team = 1;
	if (type == "Tank") {
		this->texture.loadFromFile("resources/towers/3_tower.png");
		this->sprite.setTexture(texture);
		this->view = 245.f;
		this->b_dmg = 85;
		this->pen = false;
		this->recoil = 7;
		this->range.setRadius(view);
	}
	else if (type == "Sniper") {
		this->texture.loadFromFile("resources/towers/2_tower.png");
		this->sprite.setTexture(texture);
		this->view = 300.f;
		this->b_dmg = 35;
		this->pen = true;
		this->recoil = 10;
		this->range.setRadius(view);
	}
	else {
		this->texture.loadFromFile("resources/towers/1_tower.png");
		this->sprite.setTexture(texture);
		this->view = 205.f;
		this->b_dmg = 30;
		this->recoil = 5;
		this->range.setRadius(view);
	}
	this->recoiltimer = recoil;
	this->range.setFillColor(sf::Color::Black);
}

Tower::~Tower()
{
}

void Tower::TowerBuild(sf::RenderWindow& window, sf::Vector2i& mouse_pos, sf::Event& event)
{
	bool builded = false;
	mouse_pos = sf::Mouse::getPosition(window);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				mouse_pos = sf::Mouse::getPosition(window);
				this->sprite.setPosition(mouse_pos.x, mouse_pos.y);
				this->range.setPosition(this->sprite.getPosition().x - view + 64, this->sprite.getPosition().y - view + 64);
				builded = true;
				break;
			}
		}
		if (builded == true)
			break;
	}
}

bool Tower::CheckRange(Enemy& enemy)
{
	if (enemy.hitted == false)
	{
		if (pow((enemy.getPos().x - this->range.getPosition().x), 2) + pow((enemy.getPos().y - this->range.getPosition().y), 2) < pow(this->view, 2)) 
		{
			return shot(enemy);
		}
	}
	return false;
}

bool Tower::shot(Enemy& enemy)
{
	if (recoiltimer == recoil)
	{
		if (pen == true)
		{
			enemy.setHp(enemy.getHp() - b_dmg);
		}
		else if (b_dmg - enemy.getAr() > 0)
		{
			enemy.setHp(enemy.getHp() - (b_dmg - enemy.getAr()));
		}
		recoiltimer = 0;
		if (enemy.getHp() <= 0)
		{
			enemy.hitted = true;
			return true;
		}
	}
	else
		recoiltimer++;
	return false;
}
