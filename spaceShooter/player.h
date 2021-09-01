#pragma once

#include "SFML\Graphics.hpp"
#include  "SFML\System.hpp"
#include  "SFML\Audio.hpp"
#include <iostream>
#include <vector>

using namespace sf;

class Player
{
private:
	unsigned playerNumber;
	Texture* texture;
	Sprite sprite;
	RectangleShape hitBox;

	int controls[5];

	int level;
	int exp;
	int expNext;

	int hp;
	int hpMax;

	int damage;
	int damageMax;

	int score;
public:
	//static variables
	
	Player(Texture* texture, 
		int UP = 22, int DOWN = 18,
		int LEFT = 0, int RIGHT = 3,
		int SHOOT = 57);
	virtual ~Player();
	void Movement();
	void Update();
	void Draw(RenderTarget& target);
	
	static unsigned players;

};

