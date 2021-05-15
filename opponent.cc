#include "opponent.h"
#include <iostream>
#include "cpputils/graphics/image.h"
#include "stddef.h"

void Opponent::Create() {
  graphics::Image opponent(50, 50);
  graphics::Color black(0, 0, 0);               // spy outlines
  graphics::Color skin(210, 138, 39);           // spy skins
  graphics::Color gray(50, 49, 49);             // belts and hand bomd
  graphics::Color bright_red(251, 44, 0);       // fuse tips
  graphics::Color bright_yellow(243, 255, 83);  // fuse tips
  graphics::Color brown(133, 81, 8);            // fuse
  graphics::Color noir(30, 27, 35);             // use for spy and bomb
  // Hat
  opponent.DrawRectangle(15, 3, 18, 6, black);  // outline
  opponent.DrawRectangle(6, 9, 38, 3, black);   // bottom
  //
  opponent.DrawRectangle(17, 5, 13, 4, noir);  // inside
  // Face
  opponent.DrawRectangle(23, 13, 3, 3, black);   // left eye
  opponent.DrawLine(29, 13, 29, 15, black);      // right eye
  opponent.DrawRectangle(30, 12, 3, 18, black);  // right
  opponent.DrawLine(29, 24, 29, 28, black);      // left face 1
  opponent.DrawLine(28, 23, 28, 27, black);      // left face 2
  opponent.DrawLine(27, 22, 27, 26, black);
  opponent.DrawLine(26, 21, 26, 26, black);
  opponent.DrawLine(25, 20, 25, 26, black);
  opponent.DrawLine(24, 19, 24, 23, black);
  opponent.DrawLine(23, 18, 23, 22, black);
  opponent.DrawLine(22, 17, 22, 21, black);
  opponent.DrawLine(21, 16, 21, 20, black);
  opponent.DrawLine(20, 15, 20, 19, black);
  opponent.DrawLine(19, 14, 19, 18, black);
  opponent.DrawLine(18, 13, 18, 17, black);
  opponent.DrawLine(17, 12, 17, 17, black);
  opponent.DrawLine(16, 12, 16, 15, black);
  opponent.DrawLine(15, 12, 15, 14, black);
  //
  opponent.DrawLine(18, 12, 29, 12, skin);
  opponent.DrawLine(19, 13, 22, 13, skin);
  opponent.DrawLine(20, 14, 22, 14, skin);
  opponent.DrawLine(21, 15, 21, 16, skin);
  opponent.DrawLine(22, 16, 29, 16, skin);
  opponent.DrawLine(23, 17, 29, 17, skin);
  opponent.DrawLine(24, 18, 29, 18, skin);
  opponent.DrawLine(25, 19, 29, 19, skin);
  opponent.DrawLine(26, 20, 29, 20, skin);
  opponent.DrawLine(27, 21, 29, 21, skin);
  opponent.DrawLine(28, 22, 29, 22, skin);
  opponent.SetColor(29, 23, skin);
  opponent.DrawRectangle(26, 13, 3, 3, skin);
  // Body
  opponent.DrawRectangle(25, 27, 2, 23, black);  // right sides
  opponent.DrawRectangle(17, 18, 2, 32, black);  // left sides
  opponent.DrawRectangle(19, 29, 6, 2, black);
  opponent.DrawRectangle(19, 34, 6, 2, black);
  opponent.DrawRectangle(19, 43, 6, 2, black);
  opponent.DrawRectangle(19, 48, 6, 2, black);
  opponent.DrawRectangle(21, 34, 2, 7, black);
  opponent.DrawRectangle(21, 45, 2, 3, black);
  //
  opponent.DrawRectangle(19, 36, 2, 7, noir);
  opponent.DrawRectangle(23, 36, 2, 7, noir);
  opponent.DrawRectangle(19, 45, 2, 3, noir);
  opponent.DrawRectangle(23, 45, 2, 3, noir);
  opponent.DrawRectangle(19, 31, 6, 3, gray);
  opponent.DrawRectangle(19, 24, 6, 5, noir);
  opponent.DrawLine(19, 23, 23, 23, noir);
  opponent.DrawLine(19, 22, 22, 22, noir);
  opponent.DrawLine(19, 21, 21, 21, noir);
  opponent.DrawLine(19, 20, 20, 20, noir);
  opponent.SetColor(19, 19, noir);
  // left arm
  opponent.DrawRectangle(10, 18, 7, 2, black);
  opponent.DrawRectangle(10, 20, 2, 4, black);
  opponent.DrawRectangle(8, 24, 9, 2, black);
  opponent.DrawRectangle(8, 26, 2, 2, black);
  opponent.DrawRectangle(8, 28, 9, 2, black);
  opponent.DrawRectangle(10, 30, 2, 3, black);
  opponent.DrawRectangle(10, 33, 7, 2, black);
  //
  opponent.DrawRectangle(12, 20, 5, 4, noir);
  opponent.DrawRectangle(10, 26, 7, 2, noir);
  opponent.DrawRectangle(12, 30, 5, 3, skin);
  // Right arm
  opponent.DrawRectangle(33, 19, 12, 8, black);
  opponent.DrawLine(35, 27, 40, 27, black);
  opponent.DrawRectangle(37, 21, 2, 5, noir);
  opponent.DrawRectangle(33, 21, 2, 4, noir);
  opponent.DrawRectangle(41, 21, 2, 4, skin);
  // dynamite
  opponent.DrawRectangle(41, 27, 3, 3, bright_red);
  opponent.DrawRectangle(41, 16, 3, 3, bright_red);
  opponent.DrawLine(42, 15, 42, 13, brown);
  opponent.DrawLine(41, 13, 40, 13, brown);
  opponent.DrawLine(38, 13, 39, 13, bright_red);
  opponent.DrawLine(38, 14, 38, 15, bright_red);
  opponent.DrawLine(36, 16, 38, 16, bright_yellow);
  opponent.SaveImageBmp("Opponent.bmp");
};

void Opponent::Draw(graphics::Image &o_image) {
  Opponent op_sprite;
  op_sprite.Create();
  graphics::Image o_sprite;
  o_sprite.Load("Opponent.bmp");
  // goes through the pixels of the sprite
  for (int row = 0; row < width_; row++) {
    for (int col = 0; col < height_; col++) {
      graphics::Color current = o_sprite.GetColor(row, col);
      o_image.SetColor(x_ + row, y_ + col, current);
    }
  }
};

void Opponent::Move(const graphics::Image &screen) {
  SetX(GetX() + 1);
  SetY(GetY() + 1);
  if (IsOutOfBounds(screen) == true) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
};

std::unique_ptr<class OpponentProjectile> Opponent::LaunchProjectile() {
  int count = 0;
  std::unique_ptr<OpponentProjectile> projectiles;
  // it should return either nullptr or std::unique_ptr
  if (count < 5) {
    count++;
    return nullptr;
  } else {
    projectiles = std::make_unique<OpponentProjectile>(GetX(), GetY() + 5);
    std::unique_ptr<OpponentProjectile> projectiles;
    return projectiles;
  }
}

void OpponentProjectile::Create() {
  graphics::Image o_projectile(5, 5);
  graphics::Color bright_red(251, 44, 0);
  graphics::Color bright_yellow(243, 255, 83);  // fuse tips
  graphics::Color brown(133, 81, 8);            // fuse
  graphics::Color light_gray(118, 112, 112);    // TNT label
  graphics::Color dynamite(118, 112, 113);      // TNT
  o_projectile.DrawLine(1, 2, 3, 2, dynamite);
  o_projectile.DrawLine(1, 3, 3, 3, light_gray);
  o_projectile.DrawLine(1, 4, 3, 4, dynamite);
  o_projectile.DrawLine(2, 1, 2, 0, brown);
  o_projectile.SetColor(3, 0, bright_yellow);
  o_projectile.SetColor(4, 0, bright_red);
  o_projectile.SaveImageBmp("o_bomb.bmp");
};

void OpponentProjectile::Draw(graphics::Image &op_image) {
  OpponentProjectile opp_sprite;
  opp_sprite.Create();
  graphics::Image o_bomb_sprite;
  o_bomb_sprite.Load("o_bomb.bmp");
  // goes through the pixels of the sprite
  for (int row = 0; row < width_; row++) {
    for (int col = 0; col < height_; col++) {
      graphics::Color current = o_bomb_sprite.GetColor(row, col);
      op_image.SetColor(x_ + row, y_ + col, current);
    }
  }
};

void OpponentProjectile::Move(const graphics::Image &screen) {
  SetX(GetX() + 1);
  SetY(GetY() + 1);
  if (IsOutOfBounds(screen) == true) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
};
