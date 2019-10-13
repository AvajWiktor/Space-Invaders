#pragma once
#include "Enemy.h"
#include "Bullet.h"
#include <list>
class BossEnemy :
	public Enemy
{
public:
	BossEnemy(std::string dir, Vector2f position);
	~BossEnemy();
	void update(std::list<Bullet*> &b, int timer);
	virtual void update(int timer) {

	}
	virtual void update() {

	}
private:
	void ability(std::list<Bullet*> &b, int timer);
	std::string typ_ = "boss";
};

