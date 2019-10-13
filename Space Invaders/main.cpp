#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include"Bullet.h"
#include "WeakEnemy.h"
#include "BossEnemy.h"
#include"Item.h"
#include<vector>
#include <list>
#include "Menu.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>


using namespace std;
using namespace sf;

SYSTEMTIME cs;
string scoreData;
Player Statek("grafiki/statek.png");
Menu *meni = new Menu();
float score, scoreCounter = 0;
bool wave = false;
bool isBossMusicPlay = true;
bool isCasualMusicPlay = true;
bool isVictory = false;
bool isLose = false;
bool isScoreSave = true;
bool isStart = false;
bool isRanking = false;
bool isExit = false;
bool isMenu = true;
bool boss_ = true;
int level = 1;
int enemy_counter=0;
float v_ship = 2.0;
int timex=0;
int enemy_timex = 0;
bool time_start = false;
Vector2f mousePos;
list<Bullet*> EnemyBulletsList;
list<Bullet*> BulletsList;
list<Enemy*> EnemyList;
list<Item*> ItemList;

// create the window
sf::RenderWindow window(sf::VideoMode(800, 600), "My window");


void shootingTimer()
{
	if (time_start) {
		timex += 1;
		if (timex == 30) {
			time_start = false;
			timex = 0;
		}
	}
}
void enemiesTimer() {
	enemy_timex += 1;
	if (enemy_timex == 301)
	{
		enemy_timex = 0;
	}

}
void ruch() {
	
	if (Keyboard::isKeyPressed(Keyboard::Key::A))
	{
		Statek.move(-v_ship);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D))
	{
		Statek.move(v_ship);
	}
}
void drawingBullets () {
	for (auto itr = BulletsList.begin(); itr != BulletsList.end(); itr++)
	{
		if ((*itr)->getPosition().y > 0) {
			(*itr)->animate(enemy_timex);
			window.draw((*itr)->getBullet());
			
		}
		else {
			itr = BulletsList.erase(itr);
			break;
		}
		
	}
	if (level == 3) {
		for (auto itr = EnemyBulletsList.begin(); itr != EnemyBulletsList.end(); itr++)
		{
			
			if ((*itr)->getPosition().y < 800) {
				(*itr)->animate(enemy_timex);
				window.draw((*itr)->getBullet());

			}
			else {
				itr = EnemyBulletsList.erase(itr);
				break;
			}

		}
	}
	
}
void drawingEnemies() {
	
	if (level == 3) {
		auto it = EnemyList.begin();
		(*it)->draw(window);
		(*it)->update(EnemyBulletsList, enemy_timex);
	}
	else {
		for (auto itr = EnemyList.begin(); itr != EnemyList.end(); itr++)
		{
			if ((*itr)->getPosition().y < 800) {

				(*itr)->update();

				(*itr)->draw(window);


			}
			else {
				itr = EnemyList.erase(itr);
				break;
			}
		}
	}
}
void drawingItems() {
	for (auto i = ItemList.begin(); i != ItemList.end(); i++)
	{
		(*i)->draw(window);
		(*i)->animate();
	}
}
void makeItem(int a, Vector2f position) {
	Item *temp = new Item(a,position);
	ItemList.push_back(temp);
}
void drop(Vector2f position) {
	int a = (rand() % 10) +0;

	if (a <3) {
		
		makeItem(1,position);
	}
	else if (a ==4) {
		makeItem(2,position);
	}
	else if (a >7) {
		makeItem(3,position);
	}
}
void addEnemies() {
	if (enemy_timex == 300 && level==1 && !wave)
	{
		for (int i = 0; i < 10; i++)
		{
			WeakEnemy *temp = new WeakEnemy("grafiki/enemy.png", Vector2f(120 + i * 60, -100),"enemy1");
			EnemyList.push_back(temp);
		}
		wave = true;
	}
	else if (enemy_timex%60  == 0 && level == 2&&enemy_timex!=0) {
		
			WeakEnemy *temp = new WeakEnemy("grafiki/enemy.png", Vector2f(300, -100 ), "enemy2");
			EnemyList.push_back(temp);
		
	}
	else if (level == 3 && boss_ == true) {
		BossEnemy *temp = new BossEnemy("grafiki/boss.png", Vector2f(400, -100));
		EnemyList.push_back(temp);
		boss_ = false;
	}
}
void collisionWithBullets()
{
	
	if (level == 3) {
		for (auto i = EnemyBulletsList.begin(); i != EnemyBulletsList.end(); )
		{
			if (Statek.getHeart() != 0) {


				if ((*i)->collision(Statek.getShip())) {
					Statek.dealDmg();
					i = EnemyBulletsList.erase(i);
				}
				else i++;
			}
			else { isLose = true; break; }
			
		}
		if (BulletsList.size()) {
			auto e = EnemyList.begin();
			for (auto b = BulletsList.begin(); (b != BulletsList.end()) && BulletsList.size(); )
			{
				if ((*b)->collision((*e)->getEnemy())) {
					(*e)->dealDmg((*b)->getDmg());
					b = BulletsList.erase(b);
					if ((*e)->getHp() <= 0) {
						
						EnemyList.clear();
						level = 4;
						score = 10000000 /scoreCounter ;
						break;
					}
				}
				else b++;
			}
		}
	}
	else {
		if (BulletsList.size()) {
			for (auto e = EnemyList.begin(); e != EnemyList.end() && !EnemyList.empty(); ) {
				
				for (auto b = BulletsList.begin(); (b != BulletsList.end()) && BulletsList.size() ; ){

					if ((*b)->collision((*e)->getEnemy())) {

						(*e)->dealDmg((*b)->getDmg());
						b = BulletsList.erase(b);
						if ((*e)->getHp() <= 0) {

							drop((*e)->getPosition());
							
							
							
							e=EnemyList.erase(e);
							
							enemy_counter++;
							break;
						}
					}
					else b++;
				}
				if (e == EnemyList.end()) {
					break;
				}
				else {
					e++;
				}
				
			}
		}
	}
}
void collisionWithItems() {
	for (auto i = ItemList.begin(); i !=ItemList.end(); )
	{
		if ((*i)->interact(Statek)) {
			i = ItemList.erase(i);
		}
		else i++;
	}
}
void shooting() {
	if (Keyboard::isKeyPressed(Keyboard::Key::Space) && !time_start) {

		Bullet* B1 = new Bullet(Statek.getWeapon(), Statek.getPosition());
		BulletsList.push_back(B1);
		time_start = true;
	}
}
void reset() {
	Statek.setHp();
	score = scoreCounter = 0;
	isBossMusicPlay = true;
	isCasualMusicPlay = true;
	isVictory = false;
	isScoreSave = true;
	isLose = false;
	isStart = false;
	isRanking = false;
	isExit = false;
	isMenu = true;
	boss_ = true;
	level = 1;
	EnemyList.clear();
	BulletsList.clear();
	EnemyBulletsList.clear();
	ItemList.clear();
	enemy_timex = 0;
	enemy_counter = 0;
	timex = 0;
	meni->stopMusic();
}
void end() {
	level = 4;
	isCasualMusicPlay = false;
	isBossMusicPlay = false;
	isLose = false;
	meni->playVictoryMusic(isVictory);

}
void lose() {
	meni->lose();
	
}
void gameLogic() {

	if (EnemyList.empty()) {
		wave = false;
	}
	if (isLose) {
		lose();
		
	}
	if (isCasualMusicPlay) {
		meni->playCasualMusic(isCasualMusicPlay);
	}
	if (isBossMusicPlay && level == 3) {

		meni->playBossMusic(isBossMusicPlay);
	}
	if (isVictory && level == 4) {
		end();
		
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
	{
		reset();
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::End)) {
		level = 4;
		isVictory = true;
	}
	if (enemy_counter == 20) {
		enemy_counter = 0;
		EnemyList.clear();
		level++;
		
	}
	if (isStart) {
		isMenu = false;
	}
	if (isExit) {
		window.close();
	}
	if (isRanking) {
		isMenu = false;
	}
	if (level == 4 && isScoreSave) {
		isVictory = true;
		fstream plik;
		plik.open("ranking.txt", ios::app);
		scoreData = to_string(cs.wYear) + "-" + to_string(cs.wMonth) + "-" + to_string(cs.wDay) + "  " + to_string(cs.wHour + 2) + ":" + to_string(cs.wMinute) + ":" + to_string(cs.wSecond) + " ---- Score: "+ to_string(score);
		plik << scoreData<<endl;
		plik.close();
		isScoreSave = false;
	}
	
	
	
}
int main() {
	srand(time(NULL));
	GetSystemTime(&cs);
	window.setFramerateLimit(60);
	Texture menuTexture, background;
	Sprite menu,tlo;
	background.loadFromFile("grafiki/tlo.png");
	tlo.setTexture(background);
	tlo.setScale(2,2);
	menuTexture.loadFromFile("grafiki/men.png");
	menu.setTexture(menuTexture);
	menu.setScale(3.125,2.69);
	
	
	

	
	while (window.isOpen()) {
		scoreCounter++;
		mousePos.x = Mouse::getPosition(window).x;
		mousePos.y = Mouse::getPosition(window).y;
		gameLogic();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		if (isMenu) {
			window.draw(menu);
			
			meni->draw(window, mousePos);
			meni->collision(mousePos, isStart, isExit, isRanking);
		}
		else if (isRanking) {
			meni->drawRanking(window);
		}
		else if (level==4)
		{
			meni->drawEndgame(window);
		}
		else if (isLose) {
			meni->drawLose(window);
		}
		else {
			window.draw(tlo);
			drawingItems();
			collisionWithItems();
			drawingBullets();
			addEnemies();
			shootingTimer();
			enemiesTimer();
			shooting();
			ruch();
			drawingEnemies();
			collisionWithBullets();
			Statek.update();
			Statek.draw(window);
		}
		window.display();
	}
	return 0;
}