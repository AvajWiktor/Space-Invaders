#include "Enemy.h"
#include<SFML/Graphics.hpp>



Enemy::Enemy()
{
	

}

void Enemy::setVelocity(Vector2f v)
{
	this->velocity_ = v;
}

void Enemy::draw(RenderWindow &window)
{
	window.draw(this->enemy_ship_);

}

void Enemy::move(Vector2f s)
{
	this->enemy_ship_.move(s);
	this->position_ += this->enemy_ship_.getPosition();
}

void Enemy::setType(std::string tp)
{
	this->typ_ = tp;
}

void Enemy::setTex(std::string dir)
{
	this->enemy_texture_.loadFromFile(dir);
	this->enemy_ship_.setTexture(this->enemy_texture_);
	this->enemy_ship_.setScale(1, 1);
	this->enemy_ship_.setOrigin(28 / 2, 16 / 2);
}
void Enemy::setTex(std::string dir, Vector2i origin)
{
	this->enemy_texture_.loadFromFile(dir);
	this->enemy_ship_.setTexture(this->enemy_texture_);
	this->enemy_ship_.setScale(1, 1);
	this->enemy_ship_.setOrigin(origin.x , origin.y );
}

void Enemy::setPosition(Vector2f position)
{
	this->position_ = position;
	this->enemy_ship_.setPosition(this->position_);
}

void Enemy::setHp()
{
	if (this->typ_ == "enemy1") {
		this->hp_ = 50;
	}
	else if (this->typ_ == "enemy2") {
	this->hp_ = 20;
	}
	else if (this->typ_ == "boss") {
		this->hp_ = 500;
	}
}








std::string Enemy::getType()
{
	return this->typ_;
}

Vector2f Enemy::getPosition()
{
	return this->enemy_ship_.getPosition();
}

Sprite Enemy::getEnemy()
{
	return this->enemy_ship_;
}

int Enemy::getHp()

	{
		return this->hp_;
	}

Vector2f Enemy::getVelocity()
{
	return this->velocity_;
}

void Enemy::dealDmg(int dmg)
{
	this->hp_ -= dmg;
}


