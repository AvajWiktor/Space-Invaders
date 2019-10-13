#include "Bullet.h"



Bullet::Bullet(int nr,Vector2f position)
{
	std::string dir;
	if (nr==1 ) {
		dir = "grafiki/naboj1.png";
		this->setDmg(100);
		this->setType(1);
	}
	else if (nr ==2) {
		dir = "grafiki/naboj2.png";
		this->setDmg(20);
		this->setType(2);
	}
	
	this->setText(dir);
	this->setPosition(position);
	this->setVelocity(-5);
	
}
Bullet::Bullet(std::string dir, Vector2f position, Vector2f Velocity) {

	this->setDmg(3);
	this->setType(3);
	this->setText(dir);
	this->setPosition(position);
	this->setVelocity(Velocity);
}

Sprite Bullet::getBullet()
{
	return this->bullet_;
}



void Bullet::setText(std::string dir)
{
	this->dir_ = dir;
	this->bullet_texture_.loadFromFile(dir);
	this->bullet_.setTexture(this->bullet_texture_);
	this->bullet_.setScale(2, 2);
	this->bullet_.setOrigin(4/2,12/2);
}

void Bullet::setPosition(Vector2f position)
{
	this->bullet_.setPosition(position);
}

bool Bullet::collision(Sprite temp)
{
	if (this->bullet_.getGlobalBounds().intersects(temp.getGlobalBounds())) {
		return true;
	}
	else return false;
}

void Bullet::animate(int timer)
{
	if (this->type_ == 2) {
		if (timer % 30 == 0) {
			if (this->dir_=="grafiki/naboj2.png") {
				this->dir_ = "grafiki/naboj21.png";
				this->setText("grafiki/naboj21.png");
			}
			else if (this->dir_ == "grafiki/naboj21.png") {
				this->dir_ = "grafiki/naboj2.png";
					this->setText("grafiki/naboj2.png");
			}
		}
	}
	this->bullet_.move(this->velocity_);
}



/*void Bullet::draw(RenderWindow &window)
{
	window.draw(bullet_);
}
*/
Vector2f Bullet::getPosition()
{
	return this->bullet_.getPosition();
}

int Bullet::getType()
{
	return this->type_;
}

int Bullet::getDmg()
{
	return this->dmg_;
}

void Bullet::setVelocity(float v)
{
	this->velocity_.y = v;
}

void Bullet::setVelocity(Vector2f v)
{
	this->velocity_ = v;
}

void Bullet::setDmg(int dmg)
{
	this->dmg_ = dmg;
}

void Bullet::setType(int type)
{
	this->type_ = type;
}


