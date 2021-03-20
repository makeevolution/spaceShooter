#pragma once

#include "SFML\Graphics.hpp"
#include  "SFML\System.hpp"
#include  "SFML\Audio.hpp"
#include<iostream>

using namespace sf;

class Player
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
	Player(Texture* texture);
	virtual ~Player();
	void Movement();
	void Update();
	void Draw(RenderTarget& target);
};

