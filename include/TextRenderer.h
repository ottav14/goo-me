#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

typedef struct {
	SDL_Renderer *renderer;
	TTF_Font *font;
} TextRenderer;

TextRenderer* createTextRenderer(SDL_Renderer *renderer, TTF_Font *font);
void renderText(TextRenderer *textRenderer, const std::string& text, int x, int y, SDL_Color color);

#endif 

