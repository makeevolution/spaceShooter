#include "enemy.h"

Enemy::Enemy(Texture* texture, Vector2u windowBounds,
	Vector2f position, Vector2f direction,
	Vector2f scale, int type,
	int hpMax, int damageMax, int damageMin) {

	this->texture = texture;
	this->sprite.setTexture(*this->texture);

	this->type = type;
	this->hpMax = hpMax;
	this->damageMax = damageMax;
	this->damageMin = damageMin;

	this->sprite.setPosition(windowBounds.x, rand()%windowBounds.y + this->sprite.getGlobalBounds().height);
	this->hp = hpMax;
}

Enemy::~Enemy(){}

void Enemy::takeDamage(int damage) {
	this->hp -= damage;
	if (this->hp <= 0)
	{
		this->hp = 0;
	}
};
void Enemy::Update() {
	switch (this->type)
	{
	case 0:
		this->sprite.move(-10.f, 0.f);
		break;
	default:
		break;
	}
};
void Enemy::Draw(RenderTarget& target) {
	target.draw(this->sprite);
};
