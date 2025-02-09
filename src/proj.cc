#include "raylib.h"

class Game {
 public:
  Game(const int width, const int height, const char *title, const int fps = 60);
  ~Game() { CloseWindow(); }
  void Update();
  void Draw() const;
  void Run();
};

Game::Game(const int width, const int height, const char *title, const int fps) {
  InitWindow(width, height, title);
  SetTargetFPS(fps);
}

void Game::Run() {
  while (!WindowShouldClose()) {
    Update();
    Draw();
  }
}

void Game::Draw() const {
  BeginDrawing();
    ClearBackground(BLACK);
  EndDrawing();
}

void Game::Update() {

}

int main() {
  Game game{1280, 720, "Proj"};
  game.Run();
  return 0;
}
