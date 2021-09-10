#include "player.h"
//https:\//www.youtube.com/watch?v=mYWrME4sXsU&list=PL6xSOsbVA1eZUKRu_boTDdzu8pGsVNpTo

unsigned Player::players = 0;

enum controls { UP = 0, DOWN=1,LEFT=2,RIGHT=3,SHOOT=4};

Player::Player(Texture* texture, Texture *bulletTexture,
	int UP, int DOWN,
	int LEFT, int RIGHT,
	int SHOOT
	):level(1), exp(0),expNext(100),
	hp(10),hpMax(10),damage(1),damageMax(2),
	score(0)
{
	this->texture = texture;
	this->sprite.setTexture(*this->texture);

	this->xScale = 0.12;
	this->yScale = 0.12;
	this->sprite.setScale(xScale, yScale);

	this->shootTimerMax = 25;
	this->shootTimer = this->shootTimerMax;
	this->damageTimer = 25;
	this->damageTimerMax = this->damageTimer;

	this->controls[controls::UP] = UP;
	this->controls[controls::DOWN] = DOWN;
	this->controls[controls::LEFT] = LEFT;
	this->controls[controls::RIGHT] = RIGHT;
	this->controls[controls::SHOOT] = SHOOT;

	this->bulletTexture = bulletTexture;

	Player::players++;
	this->playerNumber = Player::players;

	std::cout << (this->playerNumber) << "\n";
}
Player::~Player(){}

void Player::Movement() {
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::UP])))
		this->sprite.move(0.f, -10.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::DOWN])))
		this->sprite.move(0.f, 10.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::LEFT])))
		this->sprite.move(-10.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::RIGHT])))
		this->sprite.move(10.f, 0.f);
}

void Player::Combat() {
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::SHOOT]))
		&& this->shootTimer >= this->shootTimerMax)
	{
		// Create a new bullet, by sending in the bullet's texture and the 
		// current player's position
		this->bulletPos = { this->getPosition().x + this->getSize().x * xScale
							,this->getPosition().y + this->getSize().y * yScale / 2 };

		this->bullets.push_back(Bullet(bulletTexture, 
									   this->bulletPos, 
									   Vector2f(1.f, 0.f),
									   1.f,
									   25.f,
									   1.f));
		this->shootTimer = 0;
	}
}
// Both update and draw functions below are always called by Game.cpp, which in turn is called
// in a very fast loop by main.cpp

void Player::Update(RenderWindow* window) {
	this->Movement();
	float windowWidth = window->getSize().x;
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		// Every bullet in the vector will move by 15 pixels
		this->bullets[i].Update();
		// If the bullet goes out of window, delete the bullet from the list of bullets!
		if (window->getSize().x < bullets[i].getPosition().x)
		{
			bullets.erase(bullets.begin()+i);
		}
	}
	if (this->shootTimer < this->shootTimerMax)
		shootTimer = shootTimer++;
	if (this->damageTimer < this->damageTimerMax)
		damageTimer = damageTimer++;
	this->Combat();
};
void Player::Draw(RenderTarget& target) {
	target.draw(this->sprite);
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].Draw(target);
	}
};