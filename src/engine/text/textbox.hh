#pragma once

#include <string>

#include "raylib.h"

/**
 * @brief Simple TextBox. Currently only used for implementing TypeWriter.
 *
 */
class TextBox {
 public:
  TextBox(const std::string &text, const Font &font, const int font_size,
          const Rectangle &box);
  void Draw() const;
  void SetText(const std::string &text);
  std::string GetText() { return text_; }

 private:
  void ConstrainTextToArea();
  int font_size_;
  float spacing_;
  Rectangle box_;
  Rectangle text_area_;
  Font font_;
  std::string text_;
};