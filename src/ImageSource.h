#pragma once

#include <Windows.h>
#include <SFML/Graphics.hpp>

class ImageSource : public sf::Sprite {
public:
	ImageSource(const sf::IntRect &rect, const HWND &hwnd);
	~ImageSource();

	/*Return pixels. Don't delete this pointer!*/
	RGBQUAD * getPixels() const;
	/*Return colors. Don't delete this pointer!*/
	sf::Color * getColors() const;
	sf::Vector2u getSize() const;
	sf::Color getColor(const int &x, const int &y) const;
	sf::Color getColor(const int &number) const;
	void move(const sf::Vector2f &offset);

	/*Update pixels*/
	void update();
private:
	

	//Depens.
	sf::IntRect rect;
	HWND hwnd;
	RGBQUAD *pixels;
	sf::Color *colors;

	//SFML
	sf::Image image;
	sf::Texture texture;
	sf::Vector2u size;

	


	//Depends.
	BITMAPINFO bmi;
	HDC hDesktopDC;
	HDC hCaptureDC;
	HBITMAP hCaptureBitmap;
};