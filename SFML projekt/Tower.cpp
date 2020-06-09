#include "Tower.h"


Tower::Tower()
{
}

void Tower::SetType(std::string type) {
	this->team = 1;
	if (type == "Tank") {
		this->texture.loadFromFile("resources/towers/3_tower.png");
		this->sprite.setTexture(texture);
		this->view = 35.f;
		this->b_dmg = 65;
		this->pen = false;
		this->recoil = 8;
		this->range.setRadius(view);
	}
	else if (type == "Sniper") {
		this->texture.loadFromFile("resources/towers/2_tower.png");
		this->sprite.setTexture(texture);
		this->view = 60.f;
		this->b_dmg = 45;
		this->pen = true;
		this->recoil = 1;
		this->range.setRadius(view);
	}
	else {
		this->texture.loadFromFile("resources/towers/1_tower.png");
		this->sprite.setTexture(texture);
		this->view = 25.f;
		this->b_dmg = 20;
		this->recoil = 5;
		this->range.setRadius(view);
	}
	this->recoiltimer = recoil;
	this->range.setFillColor(sf::Color::Red);
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
				this->range.setPosition(mouse_pos.x, mouse_pos.y);
				builded = true;
				break;
			}
		}
		if (builded == true)
			break;
	}
}

void Tower::CheckRange(Enemy& enemy)
{
	if (enemy.hitted == false)
	{
		if (this->range.getGlobalBounds().contains(enemy.sprite.getPosition().x, enemy.sprite.getPosition().y));
		{
			shot(enemy);
		}
	}
}

void Tower::shot(Enemy& enemy)
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
		}
	}
	else
		recoiltimer++;
}
