#pragma once

#include "SFML\Graphics.hpp"
#include  "SFML\System.hpp"
#include  "SFML\Audio.hpp"
#include<iostream>

using namespace sf;

class player
{
private:
	Texture* texture;
	Sprite sprite;
	RectangleShape hitBox;

	int level;
	int exp;
	int expNext;

	int hp;
	int hpMax;

	int damage;
	int damageMax;

	int score;
public:
	player();
	virtual ~player();
	void Movement();
	void Update();
	void Draw();
};

