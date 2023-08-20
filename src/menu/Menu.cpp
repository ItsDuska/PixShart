#include "Menu.h"

Menu::Menu(sf::Vector2f windowSize, std::vector<ButtonInfo>& buttonInfo,sf::Font &font)
	: currentIndex(0), buttonAmount(buttonInfo.size())
{
	//init background and font...

	//buttons.resize(size);
	//int i = 0; i< size; i++

	clock.restart();

	const float offset = windowSize.y / (buttonAmount+1);
	uint16_t index = 1;
	for (ButtonInfo& info : buttonInfo)
	{
		sf::Vector2f position(
			windowSize.x / 5,
			index * offset
		);

		Button button{ info,position,20,font };
		buttons.push_back(button);
		index++;
	}
}

void Menu::render(sf::RenderTarget& window)
{
	for (Button& button : buttons)
	{
		window.draw(button);
	}
}

void Menu::move(int direction)
{
	if (clock.getElapsedTime().asSeconds() <= 0.15f)
	{
		return;
	}

	int lastIndex = currentIndex;
	currentIndex += direction;
	if (currentIndex >= buttonAmount)
	{
		currentIndex = 0;
	}
	else if (currentIndex < 0)
	{
		currentIndex = buttonAmount - 1;
	}
	buttons[currentIndex].highlight(true);
	buttons[lastIndex].highlight(false);

	clock.restart();
}



ButtonAction Menu::select()
{
	return buttons[currentIndex].getAction();
}

Menu MenuFactory::createMainMenu(sf::Vector2f windowSize, sf::Font& font)
{
	std::vector<ButtonInfo> infos;
	infos.resize(4);
	infos[0].text = "Create a new file";
	infos[0].action = ButtonAction::CREATE_NEW_FILE;

	infos[1].text = "Open a file";
	infos[1].action = ButtonAction::OPEN_FILE;

	infos[2].text = "About";
	infos[2].action = ButtonAction::ABOUT;

	infos[3].text = "Kys";
	infos[3].action = ButtonAction::EXIT;

	Menu mainMenu{ windowSize,infos,font };

	return mainMenu;
}
