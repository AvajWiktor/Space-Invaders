#pragma once
#include "Enemy.h"
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
class Menu
{
	
public:
	Menu();
	~Menu();
	void draw(RenderWindow &window, Vector2f mousePos);
	void drawEndgame(RenderWindow &window);
	void loadEndgame();
	void collision(Vector2f mousePos, bool &start, bool &exit, bool &ranking);
	void loadRanking();
	void drawRanking(RenderWindow &window);
	void loadMusic();
	void playBossMusic(bool &bossMusic);
	void playCasualMusic(bool &casualMusic);
	void playVictoryMusic(bool  &victoryMusic);
	void stopMusic();
	void lose();
	void drawLose(RenderWindow &window);


	
	
private:

	void setTex();
	void setPosition();
	Font font;
	Texture tex1, tex2, tex3, tex4,tex5,tex6;
	Sprite sp1, sp2, sp3, sp4,sp5,sp6;
	vector<Text> ranking;
	vector<Text> endgame;
	Music boss, casual,victory;
	Text gameover;
	
};

