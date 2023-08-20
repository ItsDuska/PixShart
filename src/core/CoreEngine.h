#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "menu/Menu.h"
#include <memory>

class CoreEngine
{
public:
	CoreEngine();
	bool run();
private:
	void update();
	void render();
	void pollEvents();
	sf::RenderWindow window;
	sf::Event event;
	sf::Font font;
	bool errorRaised;
	std::unique_ptr<Menu> menu;
};

