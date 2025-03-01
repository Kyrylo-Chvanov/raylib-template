#pragma once

#include <array>

#include "enums/fonts.hh"
#include "enums/textures.hh"
#include "raylib.h"

/**
 * @brief Resource manager.
 *        Used for loading and controlling textures, music, etc.
 *
 */
class ResourceManager {
 public:
  ResourceManager() : textures_{}, fonts_{} {}
  ~ResourceManager();
  const Texture2D &LoadTexture(const Textures texture, const char *path);
  const Font &LoadFont(const Fonts font, const char *path, const int font_size,
                       int *codepoints, const int codepoint_count);
  bool TextureLoaded(const Textures texture) {
    return textures_[texture].id > 0;
  }
  bool FontLoaded(const Fonts font) { return fonts_[font].texture.id > 0; }
  const Texture2D &GetTexture(const Textures texture) const {
    return textures_[texture];
  }
  const Font &GetFont(const Fonts font) const { return fonts_[font]; }

 private:
  std::array<Texture2D, TEXTURES_SIZE> textures_;
  std::array<Font, FONTS_SIZE> fonts_;
};