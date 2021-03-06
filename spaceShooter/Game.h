#pragma once
#include "player.h"
#include "enemy.h"

using namespace sf;

class Game
{
private:
	//Create the window of the game
	RenderWindow* window;

	//Create a vector of texts
	Font font;
	std::vector<Text> followPlayerTexts;
	std::vector<Text> staticPlayerTexts;

	//Create a vector of enemies
	std::vector<Enemy> enemies;

	//Create a vector of the players 6:50
	std::vector<Player> players;
	Texture playerTexture;
	Texture bulletTexture;
	Texture enemyTexture;

	float enemyTimer = 0.f;
	float enemyTimerMax = 10.f;
	float enemyMax=1;
public:
	//constructor
	Game(RenderWindow *window);
	//destructor
	virtual ~Game();
	//Accessors: Used to retrieve data of private members (in this case window)
	
	//*this means to return the window that is on the current instance of the
	//Game class, not the one that is on the "real" object
	inline RenderWindow& getWindow() { return *this->window; }
	//Setters
	
	//Functions
	void InitUI();
	void UpdateUI();
	void DrawUI();
	void Update();
	void Draw();
	void CheckCollision();
};

