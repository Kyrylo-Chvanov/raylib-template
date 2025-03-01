#include "camera.hh"

#include <algorithm>

#include "global.hh"

Camera2D SCREEN_CAMERA{Vector2{0, 0}, Vector2{GAME_WIDTH / 2.0f, GAME_HEIGHT / 2.0f}, 0, 1};

void UpdateScreenCamera(Camera2D &camera) {
  const int SCREEN_WIDTH{GetScreenWidth()};
  const int SCREEN_HEIGHT{GetScreenHeight()};
  camera.zoom = std::min(static_cast<float>(SCREEN_WIDTH) / GAME_WIDTH,
                         static_cast<float>(SCREEN_HEIGHT) / GAME_HEIGHT);
  camera.offset = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
}