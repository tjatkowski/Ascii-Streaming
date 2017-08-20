#include "Application.h"
#include <iostream>
#include <string>

int main() {
	//std::string windowName = "Nowa karta - Google Chrome";
	std::string windowName = "Counter-Strike: Global Offensive";
	//std::cin >> windowName;
	Application::setWindowName(windowName);
	Application::run();
	return 0;
}