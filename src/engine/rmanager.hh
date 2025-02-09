#pragma once

#include <array>

#include "raylib.h"
#include "textures.hh"

/**
 * @brief Resource manager.
 *        Used for loading and controlling textures, music, etc.
 *
 */
class ResourceManager {
 public:
  ResourceManager() : textures_{} {}
  ~ResourceManager();
  bool LoadTexture(const Textures scene, const char *path);
  bool TextureLoaded(const Textures scene) { return textures_[scene].id > 0; }
  const Texture2D &GetTexture(const Textures scene) const;

 private:
  std::array<Texture2D, Textures::SIZE> textures_;
};