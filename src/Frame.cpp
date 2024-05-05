#include <string>
#include "../include/Frame.h"
#include <SDL2/SDL.h>

Frame::Frame(const std::string& n, const int x, const int y, const int w, const int h) {

  name = n;
  body = {x, y, w, h};

}
