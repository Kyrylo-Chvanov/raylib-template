#include "textbox.hh"

#include "raylib.h"

TextBox::TextBox(const std::string &text, const Font &font, const int font_size,
                 const Rectangle &box)
    : font_size_{font_size},
      spacing_{},
      box_{box},
      text_area_{},
      font_{font},
      text_{text} {
  if (font_size_ < font_.baseSize) font_size_ = font_.baseSize;
  spacing_ = static_cast<float>(font_size_) / font_.baseSize;
  if (box_.width < font_size * 4) box_.width = font_size * 4;
  if (box_.height < font_size * 4) box_.height = font_size * 4;
  text_area_.x = box_.x + font_size;
  text_area_.y = box_.y + font_size;
  text_area_.width = box_.width - font_size * 2;
  text_area_.height = box_.height - font_size * 2;
  ConstrainTextToArea();
}

void TextBox::ConstrainTextToArea() {
  ulong origin{0};
  for (ulong i{0}; i < text_.size(); i++) {
    if (MeasureTextEx(font_, text_.substr(origin, i - origin).c_str(),
                      font_size_, spacing_)
            .x > text_area_.width) {
      ulong saved_index{i};
      // Find first space in text_[0 .. i]
      while (i != 0 && text_[i] != ' ') {
        i--;
      }
      // If we don't find a space, we will insert \n before text_[i]
      if (i == 0) {
        i = saved_index;
        if (i > 1) {
          text_.insert(text_.begin() + i - 1, '\n');
        } else {
          return;  // In case text font size is bigger than the text area
        }
      } else {
        text_[i] = '\n';  // If we find a space, we will replace it with \n
      }
      origin = i;
    }
  }
}

void TextBox::SetText(const std::string &text) {
  text_ = text;
  ConstrainTextToArea();
}

void TextBox::Draw() const {
  DrawRectangleRec(box_, WHITE);
  DrawRectangleRec(text_area_, RAYWHITE);
  DrawTextEx(font_, text_.c_str(), Vector2{text_area_.x, text_area_.y},
             font_size_, spacing_, RED);
}