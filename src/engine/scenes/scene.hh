#pragma once

class SceneManager;

/**
 * @brief Base class for all scenes.
 * 
 */
class Scene {
 public:
  Scene(SceneManager &scenman) : scenman_{scenman} {}
  virtual ~Scene() {};
  virtual void Update() = 0;
  virtual void Draw() const = 0;

 protected:
  SceneManager &scenman_;
};
