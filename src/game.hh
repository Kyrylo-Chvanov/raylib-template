#pragma once

#include "raylib.h"

// To use this class properly you must call InitWindow first
class Game {
 public:
  Game();
  ~Game() { CloseWindow(); }
  void Update();
  void Draw() const;
  void Run();
};