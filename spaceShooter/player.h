#pragma once

#include "Bullet.h"

using namespace sf;

class Player
{
private:
	unsigned playerNumber;

	int shootTimer;
	int shootTimerMax;
	int damageTimer;
	int damageTimerMax;

	Texture* texture;
	Sprite sprite;
	RectangleShape hitBox;

	Texture* bulletTexture;
	std::vector<Bullet> bullets;

	Vector2f bulletPos;

	int controls[5];

	int level;
	int exp;
	int expNext;

	int hp;
	int hpMax;

	int damage;
	int damageMax;

	int score;

	float xScale = 0.12; // If set above 1, bullets won't be seen
	float yScale = xScale;
public:
	//static variables
	
	Player(Texture* texture, Texture* bulletTexture,
		int UP = 22, int DOWN = 18,
		int LEFT = 0, int RIGHT = 3,
		int SHOOT = 57);
	virtual ~Player();
	void Movement();
	void Update(RenderWindow* window);
	void Draw(RenderTarget& target);
	
	static unsigned players;

};

