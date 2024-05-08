#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../include/Frame.h"
#include "../include/Button.h"

Button::Button(const std::string& n) : Frame(n) {}

void Button::display(SDL_Renderer *renderer) {

	// Get values
	std::vector<int> color = getColor();
	SDL_Rect body = getBody();

	// Draw box
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	SDL_RenderFillRect(renderer, &body); 	

}
