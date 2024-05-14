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
		virtual void display(SDL_Renderer *renderer) const;

		// Getters
		std::string getName() const;
		std::vector<int> getColor() const;
		SDL_Rect getBody() const;

		// Setters
		void setName(std::string n);
		void setColor(const int r, const int g, const int b, const int a);
		void setPosition(int x, int y);
		void setSize(int w, int h);

};

#endif // FRAME_H
