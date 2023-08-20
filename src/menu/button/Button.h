#pragma once

#include <SFML/Graphics.hpp>
#include <string>

enum class ButtonAction 
{
	CREATE_NEW_FILE,
	OPEN_FILE,
	ABOUT,
	EXIT,
	CHANGE_VALUE
};

struct ButtonInfo
{
	std::string text;
	ButtonAction action;
};


class Button : public sf::Drawable
{
public:
	Button(ButtonInfo info, sf::Vector2f position, int charSize, sf::Font &font);
	void highlight(bool enable);
	ButtonAction getAction();
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
	sf::Text text;
	ButtonAction action;
};

