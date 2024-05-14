#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Frame {
	private:
		std::string name;
		SDL_Color color;
		SDL_Rect body;
		bool clicked;

	public:
		Frame(const std::string& n);
		Frame(const std::string& n, const int x, const int y, const int w, const int h); 
		virtual void display(SDL_Renderer *renderer) const;
		virtual bool isColliding(const int x, const int y) const;
		virtual void onClicked();

		// Getters
		std::string getName() const;
		SDL_Color getColor() const;
		SDL_Rect getBody() const;
		bool isClicked() const;

		// Setters
		void setName(std::string n);
		void setColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a);
		void setPosition(const int x, const int y);
		void setSize(int w, int h);
		void setClicked(const bool val);

};

#endif // FRAME_H
