#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "ImageSource.h"
#include <iostream>


class AsciiDisplay : public sf::Drawable {
public:
	AsciiDisplay(const sf::Vector2u &size, const unsigned int charSize = 5u);

	typedef std::vector<sf::Text> Display;

	void update(const ImageSource &source, const sf::Vector2u &asciiSize);
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	static std::vector<char> ascii;


private:
	//virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	sf::Font font;
	Display display;
};