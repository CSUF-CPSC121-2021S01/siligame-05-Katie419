#include <iostream>
#include "cpputils/graphics/image.h"
#include "stddef.h"
#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H

class GameElement {
 public:
  GameElement() : x_(0), y_(0), width_(50), height_(50) {}
  GameElement(int x, int y, int width, int height)
      : x_(x), y_(y), width_(width), height_(height) {}
  // mutators
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  void SetIsActive(bool state) { is_active = state; }
  // accessors
  int GetX() const { return x_; };
  int GetY() const { return y_; };
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }
  int GetIsActive() const { return is_active; }
  virtual void Create() {
    graphics::Color black(0, 0, 0);
    graphics::Image e_sprite(5, 5);
    e_sprite.DrawRectangle(0, 0, 5, 5, black);
    e_sprite.SaveImageBmp("element.bmp");
  };
  virtual void Draw(graphics::Image &screen) = 0;
  virtual void Move(const graphics::Image &screen) = 0;
  bool IntersectsWith(const GameElement *object);
  bool IsOutOfBounds(const graphics::Image &screen) const;

 protected:
  int x_;
  int y_;
  int width_;
  int height_;
  bool is_active = true;
};

#endif  // GAMEELEMENT_H
