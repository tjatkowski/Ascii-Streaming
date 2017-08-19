#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "ImageSource.h"
#include "AsciiDisplay.h"

class Application final {
public:
	Application(const Application&) = delete;
	void operator=(const Application&) = delete;

	static void setWindowName(const std::string newName);
	static void run();

private:
	Application();
	static Application &getInstance();
	static void input();

	std::string windowName;
	HWND hwnd;

	sf::RenderWindow window;
};