#pragma once
#include "Enemy.h"
class WeakEnemy :
	public Enemy
{
public:
	WeakEnemy(std::string dir, Vector2f position, std::string typ);
	~WeakEnemy();
	void update();
	virtual void update(int timer) {

	}
	virtual void update(std::list<Bullet*> &b, int timer) {

	}
	
private:
	std::string typ_;
	int ownTimer_ = 0;
};

