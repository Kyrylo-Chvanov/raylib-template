#include "typewriter.hh"

#include <string>

#include "raylib.h"

void TypeWriter::Update() {
  if (!show || finished_) {
    return;
  }
  if (typying_) {
    // if player presses the space key, show the whole line all at once
    if (IsKeyPressed(KEY_SPACE) && stream_) {
      std::string line{};
      char next_char{static_cast<char>(stream_.get())};
      while (stream_ && next_char != '\n') {
        line += next_char;
        next_char = static_cast<char>(stream_.get());
      }
      current_line_ += line;
      textbox_.SetText(current_line_);
      typying_ = false;
      // Type the next char evert speed_ seconds
    } else if (timer_ > speed_) {
      timer_ = 0;
      char next_char{static_cast<char>(stream_.get())};
      if (stream_ && next_char != '\n') {
        current_line_ += next_char;
        textbox_.SetText(current_line_);
      } else {
        typying_ = false;
      }
    } else {
      timer_ += GetFrameTime();
    }
  } else {
    // If player wants to see the next line
    if (IsKeyPressed(KEY_SPACE)) {
      if (stream_) {
        typying_ = true;
        textbox_.SetText("");
        current_line_ = "";
      } else {
        finished_ = true;
      }
    }
  }
}