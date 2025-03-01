#pragma once

#include <array>
#include <memory>

#include "enums/scenes.hh"
#include "resman/resman.hh"
#include "scenes/scene.hh"

/**
 * @brief Controls game scenes. Offers functionalities like changing current
 * scene. Controls the resources.
 *
 */
class SceneManager {
 public:
  SceneManager() {}
  void ChangeScene(const Scenes scene);
  void Update() { scenes_[current_]->Update(); }
  void Draw() const { scenes_[current_]->Draw(); }
  ResourceManager resources;

 private:
  std::array<std::unique_ptr<Scene>, Scenes::SCENES_SIZE> scenes_;
  Scenes current_;
};