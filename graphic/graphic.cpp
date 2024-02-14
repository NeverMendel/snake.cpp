#include "graphic.h"

#include <ncurses.h>
#include <unistd.h>

#include <stdexcept>
#include <unordered_map>

#define SNAKE_PAIR 1
#define APPLE_PAIR 2
#define WALL_PAIR 3

Graphic::Graphic() : Graphic(25, 25) {}

Graphic::Graphic(int rows, int cols) : rows(rows), cols(cols) {
  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  curs_set(0);

  start_color();
  init_pair(SNAKE_PAIR, COLOR_GREEN, COLOR_GREEN);
  init_pair(APPLE_PAIR, COLOR_RED, COLOR_RED);
  init_pair(WALL_PAIR, COLOR_WHITE, COLOR_WHITE);
}

void Graphic::DisplayGame(const Game& game) {
  const Board& board = game.GetBoard();
  int rows = board.size();
  int cols = board[0].size();
  CalculateGamePosition();
  erase();
  DisplayWall();
  for (int r = 0; r < rows; r++) {
    move(starty + r, startx);
    for (int c = 0; c < cols; c++) {
      switch (board[r][c]) {
        case SNAKE:
          attron(COLOR_PAIR(SNAKE_PAIR));
          addch(' ');
          addch(' ');
          attroff(COLOR_PAIR(SNAKE_PAIR));
          break;
        case APPLE:
          attron(COLOR_PAIR(APPLE_PAIR));
          addch(' ');
          addch(' ');
          attroff(COLOR_PAIR(APPLE_PAIR));
          break;
        case EMPTY:
          addch(' ');
          addch(' ');
          break;
      }
    }
  }
  move(starty - 4, startx + width - 12);
  printw("Score: %d\n", game.GetScore());
  move(starty - 3, startx + width - 20);
  printw("Highest Score: %d", game.GetHighestScore());
  refresh();
}

const std::unordered_map<int, Direction> kMappings = {
    // wasd
    {97, LEFT},
    {115, DOWN},
    {100, RIGHT},
    {119, UP},
    // arrows
    {KEY_LEFT, LEFT},
    {KEY_DOWN, DOWN},
    {KEY_RIGHT, RIGHT},
    {KEY_UP, UP},
};

Direction Graphic::GetDirection() const {
  int ch = getch();
  if (kMappings.find(ch) != kMappings.end()) {
    return kMappings.at(ch);
  }
  throw std::invalid_argument("invalid character");
}

bool Graphic::HasDirection() const {
  int ch = getch();

  while (ch != ERR) {
    if (kMappings.find(ch) != kMappings.end()) {
      ungetch(ch);
      return true;
    }
    ch = getch();
  }

  return false;
}

void Graphic::CalculateGamePosition() {
  bool too_small = false;
  height = rows;
  width = cols * 2;

  while (LINES < height + 10 || COLS < width + 10) {
    too_small = true;
    erase();
    move(0, 0);
    printw("Current terminal size: %dx%d\nMinimum terminal size: %dx%d", COLS,
           LINES, width + 10, height + 10);
    refresh();
    usleep(1e6);
  }
  if (too_small) erase();

  starty = (LINES - height) / 2;
  startx = (COLS - width + 2) / 2;
}

void Graphic::DisplayWall() {
  attron(COLOR_PAIR(WALL_PAIR));
  move(starty - 1, startx - 2);
  for (int i = 0; i < width + 4; i++) {
    addch(' ');
  }
  for (int i = starty; i < starty + height; i++) {
    move(i, startx - 2);
    addch(' ');
    addch(' ');
    move(i, startx + width);
    addch(' ');
    addch(' ');
  }
  move(starty + height, startx - 2);
  for (int i = 0; i < width + 4; i++) {
    addch(' ');
  }
  attroff(COLOR_PAIR(WALL_PAIR));
}