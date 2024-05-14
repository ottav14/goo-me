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
	public:	
		Button(const std::string& n, TextRenderer *tr); 
		void display(SDL_Renderer *renderer) const override; 
		TextRenderer* getTextRenderer() const;
};

#endif // BUTTON_H
