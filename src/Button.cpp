#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../include/Frame.h"
#include "../include/Button.h"
#include "../include/TextRenderer.h"

Button::Button(const std::string& n, TextRenderer *tr) : Frame(n), textRenderer(tr) {}

void Button::display(SDL_Renderer *renderer) const {

	// Get values
	std::vector<int> color = getColor();
	SDL_Rect body = getBody();
	TextRenderer *textRenderer = getTextRenderer();

	// Draw box
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	SDL_RenderFillRect(renderer, &body); 	

	// Draw text
	SDL_Color textColor = {255, 255, 255, 255};

	renderText(textRenderer, "Fart", 5, 5, textColor);
	

}

TextRenderer* Button::getTextRenderer() const {
	return textRenderer;
}
