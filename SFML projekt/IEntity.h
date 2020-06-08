#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
static int count = 0;

class IEntity
{
protected:
	int id; //Identyfikator 
	int hp; //Ile ma ¿ycia
	int armour; //Ile ma pancerza
	float mvspeed; //Jak szybko siê porusza
	float view; //Jaki ma zasiêg widzenia
	int recoil; //Co ile sekund mo¿e strzelaæ
	int t_recoil; //ile minê³o od strza³u
	int b_dmg; //dmg ile bije
	bool pen; //czy dmg penetruje tarcze
	int team; // 0-przeciwnik, 1-gracz
	sf::Texture texture;

public:
	sf::Sprite sprite;

	IEntity();
	~IEntity();

	int getId() {
		return id;
	}
	int getHp() {
		return hp;
	}
	int setHp(int _hp) {
		hp = _hp;
		return hp;
	}
	int getAr() {
		return armour;
	}
	int setAr(int _ar) {
		armour = _ar;
		return armour;
	}


	sf::Vector2f getPos() {
		return sprite.getPosition();
	}

	//Renderuj i poruszaj
	void move(const float x, const float y);
	void render(const float x, const float y);
	void damage(IEntity& tower);
	void update();
};