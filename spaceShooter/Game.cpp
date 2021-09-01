#include "Game.h"

//constructor
Game::Game(RenderWindow* window) {
	this->window = window;
	this->window->setFramerateLimit(60);
	//Init textures
	playerTexture.loadFromFile("Textures/ship.png");

	//Init player(s)
	players.push_back(Player(&playerTexture));
	
}
//destructor
Game::~Game() {

}
//function definitions
void Game::Update() {
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i].Update();
	}
}

void Game::Draw() {
	this->window->clear();
	for (size_t i = 0; i < this->players.size(); i++)
	{
		players[i].Draw(*this->window);
	}
	this->window->display();
}
