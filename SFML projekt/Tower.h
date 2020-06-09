#pragma once
#include "IEntity.h"
#include "Enemy.h"
class Tower : public IEntity
{
	sf::Texture texture;
	int recoiltimer;
public:
	sf::CircleShape range;
	sf::Sprite sprite;
	Tower();
	void SetType(std::string type);
	~Tower();

	void TowerBuild(sf::RenderWindow& window, sf::Vector2i& mouse_pos, sf::Event& event);
	bool CheckRange(Enemy& enemy);
	bool shot(Enemy& enemy);

};