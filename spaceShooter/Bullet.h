#pragma once

#include "SFML\Graphics.hpp"
#include  "SFML\System.hpp"
#include  "SFML\Audio.hpp"
#include <iostream>
#include <vector>
using namespace sf;

class Bullet {
private:
	Texture* texture;
	Sprite sprite;

	float initialSpeed;
	float maxSpeed;
	Vector2f direction;
	Vector2f currentVelocity;
	float acceleration;

public:
	Bullet(Texture* texture, Vector2f position, Vector2f direction,
		float initialSpeed, float maxSpeed, float acceleration);
	virtual ~Bullet();

	void Movement();
	inline const FloatRect& getGlobalBounds()const { return this->sprite.getGlobalBounds(); }
	inline const Vector2f& getPosition()const { return this->sprite.getPosition(); }
	void Update();
	void Draw(RenderTarget& target);
};