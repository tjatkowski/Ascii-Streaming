#include "Application.h"
#include <iostream>
#include <string>

int main() {
	std::string windowName = "Terraria: Also try Minecraft!";
	//std::cin >> windowName;
	Application::setWindowName(windowName);
	Application::run();
	return 0;
}