#include "Application.h"



Application::Application() :
	windowName("NULL")
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

void Application::run(){

}
