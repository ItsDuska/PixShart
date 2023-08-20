#include "CoreEngine.h"


CoreEngine::CoreEngine()
	:window(sf::RenderWindow(sf::VideoMode(800, 600), "PixShart")), event(sf::Event()),errorRaised(false)
{
	window.setFramerateLimit(60);

	if (!font.loadFromFile("C:\\dev\\PixShart\\assets\\fonts\\yoster.ttf"))
	{
		std::cout << "\nERROR: CANT LOAD FONTS\n";
		errorRaised = true;
	}
}

bool CoreEngine::run()
{
	if (errorRaised)
	{
		return EXIT_FAILURE;
	}

	menu = std::make_unique<Menu>(MenuFactory::createMainMenu(sf::Vector2f(800,600), font));
	
	while (window.isOpen())
	{
		pollEvents();
		update();
		render();
	}
	//std::cin;
	return EXIT_SUCCESS;
}

void CoreEngine::update()
{	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		menu->move(-1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		menu->move(1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		std::cout << (int)menu->select();
	}
}

void CoreEngine::render()
{
	window.clear(sf::Color::Black);
	menu->render(window);
	window.display();
}

void CoreEngine::pollEvents()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}
