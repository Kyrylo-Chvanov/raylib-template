#include "rmanager.hh"

#include "raylib.h"
#include "textures.hh"

bool ResourceManager::LoadTexture(const Textures scene, const char *path) {
  if (scene >= Textures::SIZE) return false;
  if (TextureLoaded(scene)) UnloadTexture(textures_[scene]);
  textures_[scene] = ::LoadTexture(path);
  if (textures_[scene].id <= 0) return false;
  return true;
}

const Texture2D &ResourceManager::GetTexture(const Textures scene) const {
  return textures_[scene];
}

ResourceManager::~ResourceManager() {
  for (const auto &texture : textures_) {
    UnloadTexture(texture);
  }
}