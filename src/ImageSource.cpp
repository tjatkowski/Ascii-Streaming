#include "ImageSource.h"

ImageSource::~ImageSource(){
	delete[] pixels;
	delete[] colors;
}

RGBQUAD * ImageSource::getPixels() const
{
	return pixels;
}

sf::Color * ImageSource::getColors() const
{
	return colors;
}

sf::Vector2u ImageSource::getSize() const
{
	return size;
}



sf::Color ImageSource::getColor(const int & x, const int & y) const
{
	return getColor(y*rect.width + x);
}

sf::Color ImageSource::getColor(const int & number) const
{
	return colors[number];
}

void ImageSource::move(const sf::Vector2f & offset)
{
	rect.left += offset.x;
	rect.top += offset.y;
}

ImageSource::ImageSource(const sf::IntRect & rect, const HWND &hwnd) :
	rect(rect),
	hwnd(hwnd),
	size({ (unsigned)rect.width, (unsigned)rect.height })
{
	//HWND hDesktopWnd = hwnd;
	hDesktopDC = GetDC(hwnd);
	hCaptureDC = CreateCompatibleDC(hDesktopDC);
	hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, rect.width, rect.height);
	SelectObject(hCaptureDC, hCaptureBitmap);


	bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
	bmi.bmiHeader.biWidth = rect.width;
	bmi.bmiHeader.biHeight = rect.height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	pixels = new RGBQUAD[rect.width * rect.height];
	colors = new sf::Color[rect.width * rect.height];
	image.create(rect.width, rect.height, sf::Color(255, 0, 255));


	update();

	setTexture(texture);
}



void ImageSource::update(){
	BitBlt(hCaptureDC, 0, 0, rect.width, rect.height, hDesktopDC, rect.left, rect.top, SRCCOPY | CAPTUREBLT);
	GetDIBits(hCaptureDC, hCaptureBitmap, 0, rect.height, pixels, &bmi, DIB_RGB_COLORS);

	for (int y = 0; y < rect.height; y++) {
		for (int x = 0; x < rect.width; x++) {
			//sf::Color *tempClr = colors + (((rect.height - 1) - y)*rect.width + x);

			RGBQUAD pix = pixels[y*rect.width + x];
			sf::Color tempClr(pix.rgbRed, pix.rgbGreen, pix.rgbBlue);

			image.setPixel(x, (rect.height-1)-y, tempClr);
			colors[y*rect.width + x] = tempClr;
		}
	}
	texture.loadFromImage(image);
}


