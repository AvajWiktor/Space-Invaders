#include "Item.h"



Item::Item(int a, Vector2f position)
{
	switch (a)
	{
	case 1: {
		this->type_ = 1;
		this->setTex("grafiki/naboj2.png",Vector2f(3.0,6.0));

		break;
	}
	case 2: {
		this->type_ = 2;
		this->setTex("grafiki/shield.png", Vector2f(278.0, 278.0));
		break;
	}
	case 3: {
		this->type_ = 3;
		this->setTex("grafiki/serce.png", Vector2f(8.0, 8.0));
		break;
	}
	
	default:
		break;
	}
	this->item_.setPosition(position);

}


Item::~Item()
{
}

void Item::setTex(string dir, Vector2f origin)
{
	this->item_texture_.loadFromFile(dir);
	this->item_.setTexture(this->item_texture_);
	if (this->type_ == 2) {
		this->item_.setScale(0.05, 0.05);
	}
	else{ this->item_.setScale(2, 2); }
	
	this->item_.setOrigin(origin);
}
