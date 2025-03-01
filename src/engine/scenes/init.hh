#pragma once

#include "enums/fonts.hh"
#include "resman/resman.hh"
#include "scene.hh"
#include "scenman.hh"
#include "text/typewriter.hh"

class Init : public Scene {
 public:
  Init(SceneManager &scenman)
      : Scene(scenman),
        resources_{scenman.resources},
        writer_{
            "Hola mundo comeme los huevasos xdxdxdxd ololo\nEl anime es de "
            "otakus y pringados que no tienen nada mas que hacer que sucumbir "
            "al escapismo de dibujos animados en 2D, los consumidores de anime "
            "no tienen derechos y deberia recaer sobre ellos todo el peso de "
            "la ley, si tienes avatar de anime tu opinion no solo no cuenta "
            "sino que voy a pensar automaticamente lo contrario de lo que me "
            "digas.",
            resources_.LoadFont(FONT_MINECRAFT, "resources/fonts/Minecraft.ttf",
                                16, nullptr, 0),
            16, 0.01} {
    writer_.show = true;
  }
  void Update() override { writer_.Update(); }
  void Draw() const override { DrawRectangleRec({0, 0, GAME_WIDTH, GAME_HEIGHT}, BLACK); writer_.Draw(); }

 private:
  ResourceManager &resources_;
  TypeWriter writer_;
};