#ifndef GRAPHIC_GRAPHIC_H
#define GRAPHIC_GRAPHIC_H

#include "game/game.h"

class Graphic {
 public:
  Graphic();
  Graphic(int rows, int cols);

  void DisplayGame(const Game& game);
  Direction GetDirection() const;
  bool HasDirection() const;

 private:
  int rows;
  int cols;

  int height;
  int width;
  int starty;
  int startx;

  void CalculateGamePosition();
  void DisplayWall();
};

#endif