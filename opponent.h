#include <iostream>
#include <memory>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "stddef.h"
#ifndef OPPONENT_H
#define OPPONENT_H

class Opponent : public GameElement {
 public:
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}
  Opponent() : Opponent(0, 0) {}
  // override
  void Create() override;
  void Draw(graphics::Image &o_image) override;
  void Move(const graphics::Image &screen) override;
  std::unique_ptr<class OpponentProjectile> LaunchProjectile();
};

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  // override
  void Create() override;
  void Draw(graphics::Image &op_image) override;
  void Move(const graphics::Image &screen) override;
};

#endif  // OPPONENT_H
