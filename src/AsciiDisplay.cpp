#include "AsciiDisplay.h"

AsciiDisplay::AsciiDisplay(const sf::Vector2u &size, const unsigned int charSize)
{
	font.loadFromFile("arial.ttf");
	std::string sampleText;
	for (int i = 0; i < size.x; i++)
		sampleText += 'A';
	for (int i = 0; i < size.y; i++) {
		display.push_back(sf::Text(sampleText, font, charSize));
		display[i].setPosition(0, charSize * i);
	}

}

void AsciiDisplay::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto &it : display)
		target.draw(it);
}
