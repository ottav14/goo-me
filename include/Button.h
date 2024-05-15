#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "Frame.h"
#include "TextRenderer.h"

class Button : public Frame {
	private:
		TextRenderer *textRenderer;
		SDL_Color clickedColor;
		std::string text;
	public:	
		Button(const std::string& n, const std::string& t, TextRenderer *tr, SDL_Rect b, SDL_Color c); 
		void display(SDL_Renderer *renderer) const override; 
		void onClicked() override;

		// Getters
		TextRenderer* getTextRenderer() const;
		SDL_Color getClickedColor() const;
		std::string getText() const;

		// Setters
		void setClickedColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a);
		void setText(const std::string& t);
};

#endif 
