#include "Bullet.h"

Bullet::Bullet(Texture *texture, Vector2f position, 
	float maxSpeed, Vector2f direction, float acceleration)
{
	this->texture = texture;
	this->sprite.setTexture(*this->texture);
	this->maxSpeed = maxSpeed;

	this->currentVelocity = currentVelocity;
	this->acceleration = acceleration;
	this->direction = direction;

	this->sprite.setScale(0.15f, 0.15f);
	this->sprite.setPosition(position);
}

Bullet::~Bullet()
{

}

void Bullet::Movement()
{
	if (this->acceleration > 0.f)
	{
		if (this->currentVelocity.x < this->maxSpeed)
			this->currentVelocity.x += this->acceleration * this->direction.x;
		if (this->currentVelocity.y < this->maxSpeed)
			this->currentVelocity.y += this->acceleration * this->direction.y;
	}
	else
	{
		this->currentVelocity = Vector2f(
			this->maxSpeed * this->direction.x,
			this->maxSpeed * this->direction.y);
	}
	this->sprite.move(this->currentVelocity);
}

void Bullet::Update()
{
	this->Movement();
}

void Bullet::Draw(RenderTarget& target)
{
	target.draw(this->sprite);
}