#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#include "../include/Frame.h"
#include "../include/Button.h"
#include "../include/TextRenderer.h"

const int window_width = 1280;
const int window_height = 720;

SDL_Window *window;
SDL_Renderer *renderer;
TextRenderer *textRenderer;
TTF_Font *font;
std::vector<Frame*> frames;

bool init() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("SDL Text Rendering Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    if (TTF_Init() != 0) {
        SDL_Log("Failed to initialize SDL_ttf: %s", TTF_GetError());
        return false;
    }

    font = TTF_OpenFont("/home/dom/projects/goo-me/fonts/LiberationMono-Regular.ttf", 24);
    if (!font) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return false;
    }
    return true;

	// Set Window title
	SDL_SetWindowTitle(window, "Goo Me");


}

void quit_program() {
	TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


int main() {


	if(!init()) {
		std::cout << "Error: Could not properly initialize program." << std::endl;
	}	

	// Initialize text renderer
	textRenderer = createTextRenderer(renderer, font);
	
	// GUI	

	// Constants
	const int padding = 50;
	const int inner_padding = padding / 2;


	
	

	// Root
	Frame root = Frame("root", padding, padding, window_width/2 - padding, window_height - 2*padding);
	root.setColor(255, 0, 0, 255);
	frames.push_back(&root);

	// Inner
	Frame inner = Frame("inner",
			padding + inner_padding, padding + inner_padding,
			window_width/2 - padding - 2*inner_padding, window_height - 2*padding - 2*inner_padding);

	inner.setColor(120, 120, 120, 255);
	frames.push_back(&inner);

	// Button
	Button button = Button("words.", textRenderer);
	button.setColor(255, 0, 0, 255);
	button.setPosition(100, 100);
	button.setSize(500, 200);
	frames.push_back(&button);


	// Clear screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);


	



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
		for(Frame *frame : frames) {
			frame->display(renderer);
		}
		

		// Update the window
		SDL_RenderPresent(renderer);


	}

	// Clean up SDL 
	quit_program();

	return 0;

}
