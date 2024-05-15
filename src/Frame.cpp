#include <string>
#include <vector>
#include "../include/Frame.h"
#include <SDL2/SDL.h>

Frame::Frame(const std::string& n) {
	name = n;
	color = {255, 255, 255, 255};
	body = {0, 0, 100, 100};
	clicked = false;
}

Frame::Frame(const std::string& n, SDL_Rect b, SDL_Color c) {
	name = n;
	color = c;
	body = b;
	clicked = false;
}

Frame::Frame(const std::string& n, const int x, const int y, const int w, const int h) {
	name = n;
	color = {255, 255, 255, 255};
	body = {x, y, w, h};
	clicked = false;
}

void Frame::handle(SDL_Renderer *renderer) {
	display(renderer);
}

void Frame::display(SDL_Renderer *renderer) const {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &body); 	
}

bool Frame::isColliding(const int x, const int y) const {

	SDL_Rect body = getBody();
	return x > body.x && x < body.x + body.w &&
		   y > body.y && y < body.y + body.h;	
}

void Frame::onClicked() {}
void Frame::onUnclicked() {}






// Getters
std::string Frame::getName() const {
	return name;
}

SDL_Color Frame::getColor() const {
	return color;
}

SDL_Rect Frame::getBody() const {
	return body;
}

bool Frame::isClicked() const {
	return clicked;
}







// Setters
void Frame::setName(const std::string n) {
	name = n;
}

void Frame::setColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) {
	color = {r, g, b, a};
}

void Frame::setPosition(const int x, const int y) {
	body.x = x;
	body.y = y;
}
	
void Frame::setSize(const int w, const int h) {
	body.w = w;
	body.h = h;
}

void Frame::setClicked(const bool val) {
	clicked = val;
}



