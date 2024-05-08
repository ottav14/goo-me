#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "Frame.h"

class Button : public Frame {

	public:	
		Button(const std::string& n); 
		void display(SDL_Renderer *renderer) override; 
};

#endif // BUTTON_H
