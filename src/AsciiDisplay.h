#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class AsciiDisplay : public sf::Drawable {
public:
	AsciiDisplay(const sf::Vector2u &size, const unsigned int charSize = 5u);

	typedef std::vector<sf::Text> Display;

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	sf::Font font;
	Display display;
};