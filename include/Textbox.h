#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "Frame.h"
#include "TextRenderer.h"

class Textbox : public Frame {
	private:
		TextRenderer *textRenderer;
		SDL_Color activeColor;
		std::string text;
		bool active;
	public:	
		Textbox(const std::string& n, const std::string& t, TextRenderer *tr); 
		Textbox(const std::string& n, const std::string& t, TextRenderer *tr, SDL_Rect b, SDL_Color c); 
		void handle(SDL_Renderer *renderer) override;
		void display(SDL_Renderer *renderer) const override; 
		void onClicked() override;
		void onUnclicked() override;

		// Getters
		TextRenderer* getTextRenderer() const;
		std::string getText() const;
		bool isActive() const;
		SDL_Color getActiveColor() const;

		// Setters
		void setText(const std::string& t);
		void setActive(const bool val);
};

#endif 
