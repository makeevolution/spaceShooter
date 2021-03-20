#include "player.h"
Player::Player(Texture* texture)
	:level(1), exp(0),expNext(100),
	hp(10),hpMax(10),damage(1),damageMax(2),
	score(0)
{
	this->texture = texture;
	this->sprite.setTexture(*this->texture);

}
Player::~Player(){}

void Player::Movement() {
	if (Keyboard::isKeyPressed(Keyboard::Key(0)))
		std::cout << "A" << "\n";
}
void Player::Update() {
	this->Movement();

};
void Player::Draw(RenderTarget& target) {
	target.draw(this->sprite);
};