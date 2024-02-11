#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "board/board.h"
#include "game/game.h"
#include "graphic/graphic.h"

class Engine {
 public:
  Engine();

  void Play();

 private:
  Game game;
  Graphic graphic;
};

#endif