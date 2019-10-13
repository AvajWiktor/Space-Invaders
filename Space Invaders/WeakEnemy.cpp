#include "WeakEnemy.h"



WeakEnemy::WeakEnemy(std::string dir, Vector2f position, std::string typ)
{
	this->setType(typ);
	this->setPosition(position);
	this->setTex(dir);
	this->setHp();
	if (typ == "enemy2"){
		this->setVelocity(Vector2f(1.0, 1.0));
	}
	else if (typ == "enemy1") {
		this->setVelocity(Vector2f(0.0,3.0));
	}
}


WeakEnemy::~WeakEnemy()
{
}

void WeakEnemy::update()
{
	if (this->ownTimer_ == 300) {
		this->ownTimer_ = 0;
	}
	else this->ownTimer_++;
	if (this->getType() == "enemy1") {
		if (this->getPosition().y >= 150) {
			this->setVelocity(Vector2f(0.0,0.0));
		}
	}
	else if (this->getType() == "enemy2") {
		

		if (this->ownTimer_ % 150 == 0) {
			this->setVelocity(Vector2f(-(this->getVelocity().x), this->getVelocity().y));
		}
		
	}

	this->move(this->getVelocity());
}


