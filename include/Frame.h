#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Frame {
	private:
		std::string name;
		std::vector<int> color;
		SDL_Rect body;

	public:
		Frame(const std::string& n);
		Frame(const std::string& n, const int x, const int y, const int w, const int h); 
		std::vector<int> getColor();
		void display(SDL_Renderer *renderer);
		SDL_Rect getBody();
		void setColor(const int r, const int g, const int b, const int a);


};

#endif // FRAME_H
