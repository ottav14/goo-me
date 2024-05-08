#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#include "../include/Frame.h"
#include "../include/Button.h"

int main() {

	double window_width = 1920;
	double window_height = 1080;

	// Initialize SDL
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer);
	TTF_Init();

	
	// Set Window title
	SDL_SetWindowTitle(window, "Goo Me");



	// Initialize Goo Me
	std::vector<Frame> frames;



	// GUI	

	// Constants
	const int padding = 50;
	const int inner_padding = padding / 2;

	// Root
	Frame root = Frame("root", padding, padding, window_width/2 - padding, window_height - 2*padding);
	root.setColor(255, 0, 0, 255);
	frames.push_back(root);

	// Inner
	Frame inner = Frame("inner",
			padding + inner_padding, padding + inner_padding,
			window_width/2 - padding - 2*inner_padding, window_height - 2*padding - 2*inner_padding);

	inner.setColor(120, 120, 120, 255);
	frames.push_back(inner);

	// Button
	Button button = Button("words.");
	button.setColor(255, 255, 255, 255);
	button.setPosition(100, 100);
	button.setSize(500, 200);
	frames.push_back(button);









	// Loop variables
	bool quit = false;
	SDL_Event event;

	// Main loop
	while(!quit) {


		// Event loop
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = true;
					break;

				case SDL_KEYDOWN:
					break;


			}
		}



		// Display frames
		for(Frame frame : frames) {
			frame.display(renderer);
		}


		// Update the window
		SDL_RenderPresent(renderer);


	}

	// Clean up SDL 
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;

}
