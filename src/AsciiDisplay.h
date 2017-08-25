#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "ImageSource.h"
#include <iostream>
#include <thread>
#include <cmath>
#include <mutex>


class AsciiDisplay : public sf::Drawable {
public:
	AsciiDisplay(const sf::Vector2u &size, const unsigned int charSize = 5u);

	typedef std::vector<sf::Text> Display;

	void update(const ImageSource &source, const sf::Vector2u &asciiSize);
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	static std::vector<char> ascii;

	std::mutex displayMutex;

	sf::Font font;
	Display display;
};