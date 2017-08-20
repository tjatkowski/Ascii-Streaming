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

	ImageSource raw(sf::IntRect(100, 100, 500, 500), instance.hwnd);

	sf::Vector2u asciiSize = { 150,100 };//{ 426, 144 };
	AsciiDisplay ascii(asciiSize, 5);
	raw.setPosition(600, 0);
	sf::Clock clock;

	float movingSpeed = 10.f;

	while (instance.window.isOpen()) {
		std::cout << "FPS: " << 1.f / clock.getElapsedTime().asSeconds() << std::endl;
		clock.restart();
		input();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			raw.move({ 0.f,movingSpeed });
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			raw.move({ 0.f,-movingSpeed });
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			raw.move({ -movingSpeed,0.f });
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			raw.move({ movingSpeed,0.f });


		raw.update();
		ascii.update(raw, asciiSize);

		instance.window.clear(sf::Color::Black);
		instance.window.draw(raw);
		instance.window.draw(ascii);

		ImageSource raw(sf::IntRect(0, 0, 200, 200), instance.hwnd);

		AsciiDisplay ascii({ 128,72 }, 5);



		sf::RectangleShape shape;
		shape.setSize({ 100, 100 });

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
}

void Application::input(){
	sf::Event event;
	Application &instance = getInstance();
	while (instance.window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			instance.window.close();
	}
}