#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <SDL2/SDL.h>

class Frame {
public:

  std::string name;
  SDL_Rect body;

  Frame(const std::string& n, const int x, const int y, const int w, const int h); 

};

#endif // FRAME_H