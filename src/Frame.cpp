#include <string>
#include <vector>
#include "../include/Frame.h"
#include <SDL2/SDL.h>

Frame::Frame(const std::string& n) {
	name = n;
	color = {255, 255, 255, 255};
	body = {0, 0, 100, 100};
}

Frame::Frame(const std::string& n, const int x, const int y, const int w, const int h) {

	name = n;
	color = {255, 255, 255, 255};
	body = {x, y, w, h};


}

SDL_Rect Frame::getBody() {
	return body;
}

std::vector<int> Frame::getColor() {
	return color;
}

void Frame::setColor(const int r, const int g, const int b, const int a) {
	color = (std::vector<int>) {r, g, b, a};
}

void Frame::display(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	SDL_RenderFillRect(renderer, &body); 	
}



