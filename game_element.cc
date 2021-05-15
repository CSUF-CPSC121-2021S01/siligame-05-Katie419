#include "game_element.h"
#include <iostream>
#include "cpputils/graphics/image.h"
#include "stddef.h"

bool GameElement::IntersectsWith(const GameElement* object) {
  // object vs object
  if (GetX() < (*object).GetX() + (*object).GetWidth() &&
      GetX() + GetWidth() > (*object).GetX() &&
      GetY() < (*object).GetY() + (*object).GetHeight() &&
      GetY() + GetHeight() > (*object).GetY()) {
    return true;
  } else {
    return false;
  }
};

bool GameElement::IsOutOfBounds(const graphics::Image& screen) const {
  // corners: (0,0), (image.GetWidth(), 0)
  // (0, image.GetHeight()), (image.GetWidth(), image.GetHeight())
  // (GetX() > image.GetWidth() || GetX() + GetWidth() < image.GetWidth() ||
  //  GetY() > image.GetHeight() || GetY() + GetHeight() < image.GetHeight())
  if (GetX() > screen.GetWidth() || GetX() < 0 ||
      GetX() + GetWidth() > screen.GetWidth() || GetY() > screen.GetHeight() ||
      GetY() < 0 || GetY() + GetHeight() > screen.GetHeight() ||
      GetX() + GetWidth() < 0 || GetY() + GetHeight() < 0) {
    return true;
  } else {
    return false;
  }
};
