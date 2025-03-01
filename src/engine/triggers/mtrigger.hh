#pragma once

#include "raylib.h"
#include "camera/camera.hh"

/**
 * @brief Clickable area.
 *
 */
class MouseTrigger {
 public:
  MouseTrigger(const Rectangle &area) : area_{area} {}
  bool IsMouseButtonDown(int button) const {
    return IsMouseInsideArea() && ::IsMouseButtonDown(button);
  }
  bool IsMouseButtonPressed(int button) const {
    return IsMouseInsideArea() && ::IsMouseButtonPressed(button);
  }
  bool IsMouseButtonReleased(int button) const {
    return IsMouseInsideArea() && ::IsMouseButtonReleased(button);
  }
  bool IsMouseButtonUp(int button) const {
    return IsMouseInsideArea() && ::IsMouseButtonUp(button);
  }
  bool IsMouseInsideArea() const {
    return CheckCollisionPointRec(
        GetScreenToWorld2D(GetMousePosition(), SCREEN_CAMERA), area_);
  }
  virtual void Draw() const { DrawRectangleRec(area_, Color{255, 0, 0, 100}); }

 private:
  Rectangle area_;
};