#include "game.hh"

#include "raylib.h"
#include "engine/global.hh"

Game::Game() {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(GAME_WIDTH, GAME_HEIGHT, "proj");
  SetWindowMinSize(GAME_WIDTH / 3, GAME_HEIGHT / 3);
  SetTargetFPS(60);
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