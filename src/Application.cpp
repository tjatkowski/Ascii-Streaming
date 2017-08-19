#include "Application.h"



Application::Application() :
	windowName("NULL"),
	window(sf::VideoMode(1280,720), "Ascii Streaming")
{
	
}

Application & Application::getInstance()
{
	static Application instance;
	return instance;
}



void Application::setWindowName(const std::string newName){
	getInstance().windowName = newName;
}

void Application::run() {
	Application &instance = getInstance();
	instance.hwnd = FindWindow(NULL, instance.windowName.c_str());
	if (instance.hwnd == NULL)
		return;

	ImageSource raw(sf::IntRect(200, 200, 200, 200), instance.hwnd);

	sf::Vector2u asciiSize = { 426, 144 };
	AsciiDisplay ascii(asciiSize, 5);

	sf::Clock clock;

	while (instance.window.isOpen()) {
		std::cout << 1.f / clock.getElapsedTime().asSeconds() << std::endl;
		clock.restart();
		input();

		raw.update();
		ascii.update(raw, asciiSize);

		instance.window.clear(sf::Color(37, 37, 48));
		//instance.window.draw(raw);
		instance.window.draw(ascii);
		instance.window.display();
	}
}

void Application::input(){
	sf::Event event;
	Application &instance = getInstance();
	while (instance.window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			instance.window.close();
	}
}