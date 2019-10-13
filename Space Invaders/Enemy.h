#pragma once
#include<SFML/Graphics.hpp>
#include <list>
#include "Bullet.h"
using namespace sf;
class Enemy 
{
public:
	Enemy();
	~Enemy() = default;

	void dealDmg(int dmg);
	void draw(RenderWindow& window);
	
	virtual void update(int timer) = 0;
	virtual void update()=0;
	virtual void update(std::list<Bullet*> &b, int timer)=0;
	void move(Vector2f s);
	void setTex(std::string dir, Vector2i origin);

	//setters
	void setVelocity(Vector2f v);
	void setPosition(Vector2f position);
	
	
	//getters
	std::string getType();
	Vector2f getPosition();
	Sprite getEnemy();
	int getHp();
	Vector2f getVelocity();
protected:
	void setType(std::string tp);
	void setTex(std::string dir);
	void setHp();
	
private:
	
	
	
	String typ_;
	Sprite enemy_ship_;
	Texture enemy_texture_;
	Vector2f velocity_;
	Vector2f position_;
	int hp_;
	
	

};
