#pragma once
#include<SFML/Graphics.hpp>
#include<string>


using namespace sf;

class Bullet 
{
	friend class BossEnemy;
public:
	Bullet(int nr, Vector2f position);
	Bullet(std::string dir, Vector2f position, Vector2f Velocity);
	~Bullet() = default;
	bool collision(Sprite temp);
	void animate(int timer);
	
	
	//setters
	void setText(std::string dir);
	void setPosition(Vector2f position);
	

	//getters
	Vector2f getPosition();
	int getType();
	int getDmg();
	Sprite getBullet();

private:
	void setVelocity(float v);
	void setVelocity(Vector2f v);
	Texture bullet_texture_;
	Sprite bullet_;
	Vector2f velocity_;
	std::string dir_;
	int type_;
	int dmg_;
	void setDmg(int dmg);
	void setType(int type);
};
