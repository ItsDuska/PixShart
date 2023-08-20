#include "Button.h"

Button::Button(ButtonInfo info, sf::Vector2f position, int charSize, sf::Font& font)
{
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString(info.text);
	text.setCharacterSize(charSize);
	text.setPosition(position);
	action = info.action;
}

void Button::highlight(bool enable)
{
	if (enable)
	{
		text.setFillColor(sf::Color::Cyan);
	}
	else
	{
		text.setFillColor(sf::Color::White);
	}
}

ButtonAction Button::getAction()
{
	return action;
}

void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	window.draw(text);
}
