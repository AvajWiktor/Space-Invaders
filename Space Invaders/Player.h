#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include"Bullet.h"
#include<vector>
#include <string>
using namespace sf;
class Player
{
	friend class Item;

public:
	Player(std::string dir);
	~Player() = default;

	void update();
	void draw(RenderWindow &window);
	void move(float s);
	Vector2f getPosition();
	Sprite getShip();
	void dealDmg();
	int getHeart();
	void setHp();
	void addOneHp();
	void setWeapon(int nr);
	int getWeapon();
	void setShield();

private:
	bool is_shield_ = false;
	int hp_ = 5;
	void setTex(std::string dir);
	void setPosition();
	Sprite ship_,heart_,shield_;
	Texture ship_texture_,heart_texture_,shield_texture_;
	int weapon_;
	Vector2f position_ = Vector2f(400,500);
	std::vector<Sprite> hp_heart_;

};
