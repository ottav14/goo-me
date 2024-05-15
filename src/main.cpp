#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#include "../include/Frame.h"
#include "../include/Button.h"
#include "../include/Textbox.h"
#include "../include/TextRenderer.h"

const int window_width = 400;
const int window_height = 800;

SDL_Window *window;
SDL_Renderer *renderer;
TextRenderer *textRenderer;
TTF_Font *font;
std::vector<Frame*> frames;

void onMouseDown(const int mouseX, const int mouseY) {

	for(Frame *frame : frames) {

		if(frame->isColliding(mouseX, mouseY)) {
			frame->onClicked();
		}
		else {
			frame->onUnclicked();
		}

	}

}

void onMouseUp(const int mouseX, const int mouseY) {

	for(Frame *frame : frames) {

		frame->setClicked(false);
	}

}

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

	// Set Window title
	SDL_SetWindowTitle(window, "Goo Me");

	// Initialize text renderer
	textRenderer = createTextRenderer(renderer, font);

    return true;

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

	
	// GUI	

	// Constants
	const int padding = 30;
	const int innerPadding = padding / 2;
	
	

	// Root
	SDL_Color rootColor = {255, 255, 255, 255};
	SDL_Rect rootBody;
	rootBody.x = padding;
	rootBody.y = padding;
	rootBody.w = window_width - 2*padding; 
	rootBody.h = window_height - 2*padding; 

	Frame root = Frame("root", rootBody, rootColor);
	frames.push_back(&root);


	// Button
	SDL_Color buttonColor = {0, 0, 255, 255};
	SDL_Rect buttonBody;
	buttonBody.x = rootBody.x + innerPadding;
	buttonBody.y = rootBody.y + innerPadding;
	buttonBody.w = rootBody.w - 2*innerPadding;
	buttonBody.h = 40;

	Button button = Button("button", "Click me", textRenderer, buttonBody, buttonColor);
	frames.push_back(&button);

	// Textbox
	SDL_Color textboxColor = {200, 200, 200, 255};
	SDL_Rect textboxBody;
	textboxBody.x = rootBody.x + innerPadding;
	textboxBody.y = buttonBody.y + buttonBody.h + innerPadding;
	textboxBody.w = rootBody.w - 2*innerPadding;
	textboxBody.h = 40;

	Textbox textbox = Textbox("textbox", "Enter text", textRenderer, textboxBody, textboxColor);
	frames.push_back(&textbox);
	

	// Clear screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);


	



	// Loop variables
	bool quit = false;
	SDL_Event event;
	int mouseX, mouseY;

	// Main loop
	while(!quit) {

		// Get mouse input
		SDL_GetMouseState(&mouseX, &mouseY);

		// Event loop
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = true;
					break;

				// Input logic
				case SDL_KEYDOWN:
					break;

				case SDL_MOUSEBUTTONDOWN:
					if(event.button.button == SDL_BUTTON_LEFT) {
						onMouseDown(mouseX, mouseY);
					}
					break;

				case SDL_MOUSEBUTTONUP:
					if(event.button.button == SDL_BUTTON_LEFT) {
						onMouseUp(mouseX, mouseY);
					}
					break;

			}
		}


		// Handle frames
		for(Frame *frame : frames) {
			frame->handle(renderer);
		}
		

		// Update the window
		SDL_RenderPresent(renderer);


	}

	// Clean up 
	quit_program();

	return 0;

}
