#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "../include/Frame.h"

int main() {

  double window_width = 1920;
  double window_height = 1080;

  // Initialize SDL
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer);

  // Set Window title
  SDL_SetWindowTitle(window, "Goo Me");


  // Initialize test box
  Frame box = Frame("Box", 50, 50, 100, 100);


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

    // Draw background
    SDL_Rect bg = {0, 0, (int) window_width, (int) window_height};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &bg);

    // Draw box
    SDL_Rect boxBody = box.getBody();
    std::vector<int> color = box.getColor();
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
    SDL_RenderFillRect(renderer, &boxBody);


    // Update the window
    SDL_RenderPresent(renderer);


  }

  // Clean up SDL 
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;

}
