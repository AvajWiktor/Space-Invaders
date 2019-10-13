#pragma once
#include "Menu.h"
#include "Player.h"
class Item
{
public:
	Item(int a, Vector2f position);
	~Item();
	bool interact(Player &p) {

		if (this->item_.getGlobalBounds().intersects(p.getShip().getGlobalBounds())) {
			if (this->type_ == 1) {
				p.setWeapon(2);
			}
			else if (this->type_ == 2) {
				p.setShield();
			}
			else if (this->type_ == 3) {
				p.addOneHp();
			}
			return true;
		}
		else return false;
	}
	void draw(RenderWindow &window)
	{
		window.draw(this->item_);
	}
	void animate() {
		this->item_.move(0, 3);
	}
	void setTex(string dir, Vector2f origin);
	
private:
	Texture item_texture_;
	Sprite item_;
	int type_;
};

