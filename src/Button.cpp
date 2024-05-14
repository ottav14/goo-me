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
	SDL_Color color;
	
	if(isClicked()) {
		color = getClickedColor();
	}
	else {
		color = getColor();
	}
	

	SDL_Rect body = getBody();
	TextRenderer *textRenderer = getTextRenderer();

	// Draw box
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &body); 	

	// Draw text
	std::string text = "Poopy fart";
	SDL_Color textColor = {255, 255, 255, 255};
	const int textX = body.x + body.w / 2 - 8*text.size();
	const int textY = body.y + body.h / 2 - 12;

	renderText(textRenderer, text, textX, textY, textColor);
	

}

TextRenderer* Button::getTextRenderer() const {
	return textRenderer;
}

void Button::onClicked() {

	setColor(255, 0, 0, 255);

}

void Button::setClickedColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) {
	clickedColor = {r, g, b, a};
}

SDL_Color Button::getClickedColor() const {
	return clickedColor;
}
