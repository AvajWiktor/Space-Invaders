#include "Menu.h"
#include <fstream>




Menu::Menu()
{
	this->setTex();
	this->setPosition();
	this->loadRanking();
	this->loadMusic();
	this->loadEndgame();
	
}


Menu::~Menu()
{
}

void Menu::draw(RenderWindow &window, Vector2f mousePos)
{
	
	if (this->sp1.getGlobalBounds().contains(mousePos)) {
		window.draw(this->sp2);
	}
	else if (!(this->sp1.getGlobalBounds().contains(mousePos))) {
		window.draw(this->sp1);
	}

	 if (this->sp3.getGlobalBounds().contains(mousePos)) {
		window.draw(this->sp4);
	}
	else if (!(this->sp3.getGlobalBounds().contains(mousePos))) {
		window.draw(this->sp3);
	}
	 if (this->sp5.getGlobalBounds().contains(mousePos)) {
		 window.draw(this->sp6);
	 }
	 else if (!(this->sp5.getGlobalBounds().contains(mousePos))) {
		 window.draw(this->sp5);
	 }
}

void Menu::drawEndgame(RenderWindow &window)
{
	for (int i = 0; i < 5; i++)
	{
		window.draw(this->endgame[i]);
		if ((this->endgame[i].getPosition().y > 100 && i == 0)||(this->endgame[i].getPosition().y > 200 && i == 2)||(this->endgame[i].getPosition().y > 300 && i == 4)) {
			this->endgame[i].move(0, -1);
		}
	}

}

void Menu::loadEndgame()
{
	this->gameover.setFont(this->font);
	this->gameover.setString("Game Over");
	this->gameover.setFillColor(Color::Red);
	this->gameover.setCharacterSize(40);
	this->gameover.setOrigin(20,20);
	this->gameover.setPosition(330, 200);

	fstream plik;
	plik.open("endgame.txt", ios::in);
	for (int i = 0; i < 5; i++)
	{
		string tex;
		getline(plik, tex);

		Text tex1;
		tex1.setFont(this->font);
		tex1.setString(tex);
		tex1.setFillColor(Color::Red);
		tex1.setCharacterSize(40);
		tex1.setPosition(150, 600 + i * 50);
		this->endgame.push_back(tex1);
		
	}
}

void Menu::collision(Vector2f mousePos, bool &start, bool &exit, bool &ranking)
{
	if (this->sp1.getGlobalBounds().contains(Vector2f(mousePos))&&Mouse::isButtonPressed(Mouse::Button::Left)) {
		start = true;
	}
	else if (this->sp3.getGlobalBounds().contains(Vector2f(mousePos))&& Mouse::isButtonPressed(Mouse::Button::Left)) {
		exit = true;
	}
	else if (this->sp5.getGlobalBounds().contains(Vector2f(mousePos)) && Mouse::isButtonPressed(Mouse::Button::Left)) {
		ranking = true;
	}
}
void Menu::loadRanking()
{
	this->font.loadFromFile("arial.ttf");
	
	fstream plik;
	plik.open("ranking.txt", ios::in);
	for (int i = 0; i < 10; i++)
	{
		string tex;
		getline(plik, tex);

		Text tex1;
		tex1.setFont(this->font);
		tex1.setString(tex);
		tex1.setFillColor(Color::Red);
		tex1.setCharacterSize(40);
		tex1.setPosition(0, 50+i*50);
		this->ranking.push_back(tex1);

	}

	


}
void Menu::drawRanking(RenderWindow &window)
{
	for (int i = 0; i < 10; i++)
	{
		window.draw(this->ranking[i]);
	}
}
void Menu::loadMusic()
{
	this->victory.openFromFile("dzwieki/victory.ogg");
	this->victory.setLoop(true);
	this->victory.setVolume(100);
	this->boss.openFromFile("dzwieki/boss.ogg");
	this->boss.setLoop(true);
	this->boss.setVolume(100);
	this->casual.openFromFile("dzwieki/casual.ogg");
	this->casual.setLoop(true);
	this->casual.setVolume(100);
}
void Menu::playBossMusic(bool &bossMusic)
{
	if ( bossMusic) {
		this->casual.stop();
		this->boss.play();
		bossMusic = false;
	}
}
void Menu::playCasualMusic(bool & casualMusic)
{
	if (casualMusic) {

		this->casual.play();
		casualMusic = false;
	}
}
void Menu::playVictoryMusic(bool & victoryMusic)
{
	if (victoryMusic) {
		this->boss.stop();
		this->casual.stop();
		this->victory.play();
		victoryMusic = false;
	}
}
void Menu::stopMusic()
{
	this->casual.play();
	this->boss.stop();
	this->victory.stop();
}
void Menu::drawLose(RenderWindow & window)
{
	window.draw(this->gameover);
}
void Menu::lose() {
	this->casual.stop();
	this->boss.stop();
	this->victory.stop();
}

void Menu::setTex() {
	this->tex1.loadFromFile("grafiki/start1.png");
	this->tex2.loadFromFile("grafiki/start2.png");
	this->tex3.loadFromFile("grafiki/exit1.png");
	this->tex4.loadFromFile("grafiki/exit2.png");
	this->tex5.loadFromFile("grafiki/ranking1.png");
	this->tex6.loadFromFile("grafiki/ranking2.png");
	this->sp1.setTexture(tex1);
	this->sp1.setScale(200.0 / 472.0, 200.0 / 472);
	this->sp1.setOrigin(472 / 2, 152 / 2);
	this->sp2.setTexture(tex2);
	this->sp2.setScale(200.0 / 472.0, 200.0 / 472.0);
	this->sp2.setOrigin(472 / 2, 152 / 2);
	this->sp3.setTexture(tex3);
	this->sp3.setScale(0.5, 0.5);
	this->sp3.setOrigin(312 / 2, 152 / 2);
	this->sp4.setTexture(tex4);
	this->sp4.setScale(0.5, 0.5);
	this->sp4.setOrigin(312 / 2, 152 / 2);
	this->sp5.setTexture(tex5);
	this->sp5.setScale(0.5, 0.5);
	this->sp5.setOrigin(574 / 2, 134 / 2);
	this->sp6.setTexture(tex6);
	this->sp6.setScale(0.5, 0.5);
	this->sp6.setOrigin(574 / 2, 134 / 2);
}
void Menu::setPosition()
{
	{
		sp1.setPosition(400, 150);
		sp2.setPosition(400, 150);
		sp5.setPosition(400, 275);
		sp6.setPosition(400, 275);
		sp3.setPosition(400, 400);
		sp4.setPosition(400, 400);

	}
}
