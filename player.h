#include <iostream>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"
#include "stddef.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameElement {
 public:
  Player(int x, int y) : GameElement(x, y, 50, 50) {}
  Player() : Player(0, 0) {}
  // override
  void Create() override;
  void Draw(graphics::Image &p_image) override;

  // unique
  void Move(const graphics::Image &screen) override;
};

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  PlayerProjectile() : PlayerProjectile(0, 0) {}

  // override
  void Create() override;
  void Draw(graphics::Image &pp_image) override;
  void Move(const graphics::Image &screen) override;
  // unique
};

#endif  // PLAYER_H
