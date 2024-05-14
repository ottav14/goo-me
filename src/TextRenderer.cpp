#include "../include/TextRenderer.h"


TextRenderer* createTextRenderer(SDL_Renderer *renderer, TTF_Font *font) {
	static TextRenderer textRenderer = {renderer, font};
	return &textRenderer;
}

void renderText(TextRenderer *textRenderer, const std::string& text, int x, int y, SDL_Color color) {

    SDL_Surface* surface = TTF_RenderText_Solid(textRenderer->font, text.c_str(), color);
    if (!surface) {
        SDL_Log("Failed to create text surface: %s", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(textRenderer->renderer, surface);
    if (!texture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }

    int texW, texH;
    SDL_QueryTexture(texture, nullptr, nullptr, &texW, &texH);
    SDL_Rect dstRect = {x, y, texW, texH};
    SDL_RenderCopy(textRenderer->renderer, texture, nullptr, &dstRect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

}

