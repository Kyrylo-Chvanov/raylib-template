#pragma once

#include <sstream>

#include "global.hh"
#include "raylib.h"
#include "textbox.hh"

/**
 * @brief Interactive TextBox window. Used for dialogues and descriptions.
 *
 */
class TypeWriter {
 public:
  TypeWriter(const std::string &text, const Font &font, const int font_size,
             const float speed)
      : show{false},
        typying_{true},
        finished_{false},
        timer_{0},
        speed_{speed},
        stream_{text},
        current_line_{},
        textbox_{
            "", font, font_size,
            Rectangle{GAME_WIDTH / 2.0f - 300, GAME_HEIGHT - 200, 600, 200}} {}
  void Update();
  void Draw() const {
    if (show && !finished_) textbox_.Draw();
  }
  bool show;

 private:
  bool typying_;
  bool finished_;
  float timer_;
  float speed_;
  std::stringstream stream_;
  std::string current_line_;
  TextBox textbox_;
};