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
		;

	ImageSource raw(sf::IntRect(0, 0, 200, 200), instance.hwnd);

	AsciiDisplay ascii({ 128,72 }, 5);



	sf::RectangleShape shape;
	shape.setSize({100, 100});

	std::cout << "Helo\n";
	while (instance.window.isOpen()) {
		input();

		raw.update();
		shape.rotate(1.f);
		instance.window.clear(sf::Color(37, 37, 48));
		//instance.window.draw(ascii);
		instance.window.draw(shape);
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