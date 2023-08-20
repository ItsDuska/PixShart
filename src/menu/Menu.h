#pragma once

#include <cstdint>
#include <vector>
#include "button/Button.h"

/*
Mitä pitäs saada:
Kerro kuinka monta nappulaa
kerro jokasen nappulan nimi
kerro jokasen nappukan funktio. (func pointteri)
*/

class Menu
{
public:
	Menu(sf::Vector2f windowSize,
		std::vector<ButtonInfo> &buttonInfo,
		sf::Font& font
		);
	void render(sf::RenderTarget& window);
	void move(int direction);

	ButtonAction select();

private:
	std::vector<Button> buttons;
	//sf::Sprite background;
	int currentIndex;
	const uint16_t buttonAmount;
	sf::Clock clock;
};


namespace MenuFactory
{
	Menu createMainMenu(sf::Vector2f windowSize, sf::Font& font);

}