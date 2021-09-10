#include "Game.h"

//constructor
Game::Game(RenderWindow* window) {
	this->window = window;
	this->window->setFramerateLimit(60);
	//Init textures
	playerTexture.loadFromFile("Textures/ship.png");
	bulletTexture.loadFromFile("Textures/bullet.png");
	enemyTexture.loadFromFile("Textures/bullet.png");

	//Init fonts
	this->font.loadFromFile("Fonts/Dosis-Light.ttf");

	//Init player(s)
	players.push_back(Player(&playerTexture, &bulletTexture));
	players.push_back(Player(&playerTexture, &bulletTexture, Keyboard::I,
		Keyboard::K, Keyboard::J, Keyboard::L, Keyboard::RShift));

	//Init enemies
	this->enemies.push_back(Enemy(
		&enemyTexture,
		this->window->getSize(),
		Vector2f(0.f, 0.f),
		Vector2f(-1.f, 0.f),
		Vector2f(0.1f, 0.1f),
		0,
		rand() % 3 + 1,
		3,
		1
	));
	// VID 11 MINUTE 11
	this->InitUI();
}
//destructor
Game::~Game() {

}

//function definitions


void Game::InitUI() {
	Text tempText;
	for (size_t i = 0; i < this->players.size(); i++) {
		tempText.setFont(font);
		tempText.setCharacterSize(24);
		tempText.setFillColor(Color::White);
		tempText.setString(std::to_string(i));

		this->followPlayerTexts.push_back(tempText);

		//Static text init
		tempText.setFont(font);
		tempText.setCharacterSize(24);
		tempText.setOutlineColor(Color::White);
		tempText.setString("N/A");

		this->staticPlayerTexts.push_back(tempText);
	}
}

void Game::UpdateUI() {
	for (size_t i = 0; i < this->followPlayerTexts.size(); i++) {
		float movingTextxPos = this->players[i].getPosition().x + (this->players[i].getSize().x / 2 * this->players[i].getScale().x);
		float movingTextyPos = this->players[i].getPosition().y;
		Vector2f textPos = { movingTextxPos, movingTextyPos };
		this->followPlayerTexts[i].setPosition(textPos);
		this->followPlayerTexts[i].setString(std::to_string(i) + " | " + players[i].getHpAsString());
	}
	for (size_t i = 0; i < this->staticPlayerTexts.size(); i++) {
		this->staticPlayerTexts[i].setPosition(1920/2, 0);
		this->staticPlayerTexts[i].setString("N/A");
	}
}

void Game::DrawUI() {
	for (size_t i = 0; i < this->followPlayerTexts.size(); i++)
	{
		this->window->draw(this->followPlayerTexts[i]);
	}
	for (size_t i = 0; i < this->staticPlayerTexts.size(); i++)
	{
		this->window->draw(this->staticPlayerTexts[i]);
	}
}

void Game::Update() {
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i].Update(this->window);
	}
	
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i].Update();
	}
	this->UpdateUI();
}

void Game::Draw() {
	this->window->clear();
	for (size_t i = 0; i < this->players.size(); i++)
	{
		players[i].Draw(*this->window);
	}

	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].Draw(*this->window);
	}
	this->DrawUI();
	this->window->display();
}
