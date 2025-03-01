#include "resman.hh"

#include "enums/fonts.hh"
#include "enums/textures.hh"
#include "raylib.h"

const Texture2D &ResourceManager::LoadTexture(const Textures texture,
                                              const char *path) {
  if (TextureLoaded(texture)) UnloadTexture(textures_[texture]);
  textures_[texture] = ::LoadTexture(path);
  return textures_[texture];
}

const Font &ResourceManager::LoadFont(const Fonts font, const char *path,
                                      const int font_size, int *codepoints,
                                      const int codepoint_count) {
  if (FontLoaded(font)) UnloadFont(fonts_[font]);
  fonts_[font] = ::LoadFontEx(path, font_size, codepoints, codepoint_count);
  return fonts_[font];
}

ResourceManager::~ResourceManager() {
  for (const auto &texture : textures_) {
    UnloadTexture(texture);
  }
  for (const auto &font : fonts_) {
    UnloadFont(font);
  }
}