#include "BossEnemy.h"
#include <iostream>



BossEnemy::BossEnemy(std::string dir, Vector2f position)
{
	this->setType("boss");
	this->setPosition(position);
	this->setTex(dir, Vector2i(96,43));
	this->setHp();
	this->setVelocity(Vector2f(0.0,1.0));
	
	
}


BossEnemy::~BossEnemy()
{
}

void BossEnemy::update(std::list<Bullet*> &b ,int timer)
{
	
	if (this->getPosition().y < 100) {
		this->move(Vector2f(0.0,0.5));
	}
	
	ability(b,timer);
	
}

void BossEnemy::ability(std::list<Bullet*> &b,int timer)
{
	if(timer%150==0 && timer !=0)
	for (int i = 0; i < 5; i++)
	{
		Bullet *temp = new Bullet("grafiki/naboj3.png", this->getPosition(), Vector2f(-2.0 + i, 3.0));
		b.push_back(temp);
	}
}
