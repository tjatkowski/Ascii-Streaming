#include "AsciiDisplay.h"

std::vector<char> AsciiDisplay::ascii;

AsciiDisplay::AsciiDisplay(const sf::Vector2u &size, const unsigned int charSize)
{
	font.loadFromFile("consola.ttf");
	std::string sampleText;
	for (int i = 0; i < size.x; i++)
		sampleText += 'A';
	for (int i = 0; i < size.y; i++) {
		display.push_back(sf::Text(sampleText, font, charSize));
		display[i].setPosition(0, charSize * i);
	}
	//ascii = { ' ','.',',','°','•','¬','—','›','“','"','^','™','±','!',';','®','¤','§','€','¶','%','&','@','#' };
	ascii = { ' ','-','-','@','@' };
}

void AsciiDisplay::update(const ImageSource &source, const sf::Vector2u &asciiSize)
{
	sf::Vector2u size = source.getSize();
	sf::Color *colors = source.getColors();

	sf::Vector2f resizeFactor = { (float)size.x / asciiSize.x, (float)size.y / asciiSize.y };


	for (int y = 0; y < asciiSize.y; ++y) {
		std::string newText;
		newText.resize(asciiSize.x);
		for (int x = 0; x < asciiSize.x; ++x) {
			//sf::Color tempColor = colors[(int)((y*resizeFactor.y)*size.x + (x*resizeFactor.x))];
			sf::Color tempColor = source.getColor(x*resizeFactor.x, (size.y-1) - y*resizeFactor.y);
			float value = tempColor.r + tempColor.g + tempColor.b;
			//std::cout << value << std::endl;
			value /= 3.f; //Avarage value of RGB colors
			value = value / 255.f;
			newText[x] = ascii[(ascii.size()-1) * value];
		}
		display[y].setString(newText);
	}




	/*for (int y = 0; y < size.y; y++) {
		std::string newText;
		newText.resize(asciiSize.x);
		for (int x = 0; x < size.x; x++) {
			sf::Color color = colors[size.x * y + x];
			float value = color.r + color.g + color.b;
			value /= 3.f;
			float percent = value / 255.f;
			newText[(x/(size.x-1)) * (asciiSize.x-1)] = ascii[(ascii.size() - 1) * percent];
		}
		display[(y / (size.y - 1)) * (asciiSize.y - 1)].setString(newText);
	}*/
}

void AsciiDisplay::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto &it : display)
		target.draw(it);
}
