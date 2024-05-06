#include <string>
#include <vector>
#include "../include/Frame.h"
#include <SDL2/SDL.h>

Frame::Frame(const std::string& n, const int x, const int y, const int w, const int h) {

  name = n;
  color = {255, 255, 255, 255};
  body = {x, y, w, h};

}

SDL_Rect Frame::getBody() {
  return body;
}

std::vector<int> Frame::getColor() {
  return color;
}

void Frame::setColor(const int r, const int g, const int b, const int a) {
  color = (std::vector<int>) {r, g, b, a};
}

