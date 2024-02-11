#include "engine.h"

#include <unistd.h>

Engine::Engine() {}

void Engine::Play() {
  graphic.DisplayGame(game);
  usleep(1e5);
  while (true) {
    for (int i = 0; i < 75; i++) {
      if (graphic.HasDirection()) {
        Direction dir = graphic.GetDirection();
        game.ChangeDirection(dir);
      }
      usleep(1000);
    }
    game.Move();
    graphic.DisplayGame(game);
    if(game.GetStatus() == ENDED){
      sleep(1);
      game.Reset();
      graphic.DisplayGame(game);
    }
  }
}