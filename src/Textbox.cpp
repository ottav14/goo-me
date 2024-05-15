#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../include/Frame.h"
#include "../include/Textbox.h"
#include "../include/TextRenderer.h"

Textbox::Textbox(const std::string& n, const std::string& t, TextRenderer *tr) : Frame(n), text(t), textRenderer(tr), active(false) {}

Textbox::Textbox(const std::string& n, const std::string& t, TextRenderer *tr, SDL_Rect b, SDL_Color c) : Frame(n, b, c), text(t), textRenderer(tr), active(false) {
	activeColor = {150, 150, 150, 255};
}

void Textbox::handle(SDL_Renderer *renderer) {


	if(isActive()) {
		setText(" ");
	}
	else {
		setText("Enter text");
	}



	display(renderer);
	
}

void Textbox::display(SDL_Renderer *renderer) const {

	// Get values
	std::string text = getText();

	SDL_Color color;
	if(isActive()) {
		color = getActiveColor();
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
	SDL_Color textColor = {0, 0, 0, 255};
	const int textX = body.x + body.w / 2 - 8*text.size();
	const int textY = body.y + body.h / 2 - 12;

	renderText(textRenderer, text, textX, textY, textColor);
	

}

void Textbox::onClicked() {

	setActive(true);

}

void Textbox::onUnclicked() {

	setActive(false);

}

// Getters
TextRenderer* Textbox::getTextRenderer() const {
	return textRenderer;
}

std::string Textbox::getText() const {
	return text;
}

bool Textbox::isActive() const {
	return active;
}

SDL_Color Textbox::getActiveColor() const {
	return activeColor;
}


// Setters
void Textbox::setText(const std::string& t) {
	text = t;
}

void Textbox::setActive(const bool val) {
	active = val;
}
