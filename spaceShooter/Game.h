#pragma once
#include  "player.h" 
using namespace sf;

class Game
{
private:
	RenderWindow* window;
	player *player;
	Texture playerTexture;

public:
	Game(RenderWindow *window);
	virtual ~Game();
	//Accessors
	inline RenderWindow& getWindow() { return *this->window; }
	//Setters
	
	//Functions
	void Update();
	void Draw();
};

