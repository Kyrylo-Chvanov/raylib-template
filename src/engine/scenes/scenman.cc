#include "scenman.hh"

#include <memory>

#include "enums/scenes.hh"
#include "init.hh"

void SceneManager::ChangeScene(const Scenes scene) {
  if (!scenes_[scene]) {
    switch (scene) {
      case SCENE_INIT:
        scenes_[scene] = std::make_unique<Init>(*this);
        break;
      case SCENES_SIZE:
        return;
    }
  }
  current_ = scene;
}