#include "Player.h"


Player::Player(std::string dir)
{
	this->setPosition();
	this->setTex(dir);
	this->setHp();
	this->setWeapon(1);
}

void Player::draw(RenderWindow &window)
{
	for (int i = 0; i < this->hp_heart_.size(); i++)
	{
		window.draw(hp_heart_[i]);
	}
	if (this->is_shield_) {
		window.draw(this->shield_);
	}
	window.draw(this->ship_);
}

void Player::move(float s)
{
	this->ship_.move(s,0);
	this->position_.x += s;
	this->shield_.setPosition(this->ship_.getPosition());
}

void Player::setTex(std::string dir)
{
	this->shield_texture_.loadFromFile("grafiki/shield.png");
	this->shield_.setTexture(this->shield_texture_);
	this->shield_.setScale(0.15,0.15);
	this->shield_.setOrigin(278,278);

	this->ship_texture_.loadFromFile(dir);
	this->ship_.setTexture(this->ship_texture_);
	this->ship_.setScale(2, 2);
	this->ship_.setOrigin(28 / 2, 16/2);
}

void Player::setPosition()
{
	this->ship_.setPosition(this->position_);
}



void Player::update()
{

}



Vector2f Player::getPosition()
{
	return this->position_;
}

Sprite Player::getShip()
{
	if (this->is_shield_) {
		return this->shield_;
	}
	else {
		return this->ship_;
	}
}

void Player::dealDmg()
{
	if (this->is_shield_){
		this->is_shield_ = false;
	}
	else {
		this->hp_heart_.pop_back();
	}
}

int Player::getHeart()
{
	return this->hp_heart_.size();
}

void Player::setHp()
{
	this->hp_heart_.clear();
	this->heart_texture_.loadFromFile("grafiki/serce.png");
	this->heart_.setTexture(this->heart_texture_);
	this->heart_.setScale(2, 2);
	this->heart_.setOrigin(8,8);

	for (int i = 0; i < this->hp_; i++)
	{
		this->heart_.setPosition(50+i*32,50);
		this->hp_heart_.push_back(this->heart_);
		
	}
}

void Player::addOneHp()
{
	int place = this->hp_heart_.size();
	this->heart_.setPosition(50+ place*32,50);
	this->hp_heart_.push_back(this->heart_);
}

void Player::setWeapon(int nr)
{
	this->weapon_ = nr;
}

int Player::getWeapon()
{
	return this->weapon_;
}

void Player::setShield()
{
	this->is_shield_ = true;
}
