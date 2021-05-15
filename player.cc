#include "player.h"
#include <iostream>
#include "cpputils/graphics/image.h"
#include "stddef.h"

void Player::Create() {
  graphics::Color white(255, 255, 255);         // spy
  graphics::Color gray(50, 49, 49);             // belts and hand bomb
  graphics::Color black(0, 0, 0);               // spy outlines
  graphics::Color skin(210, 138, 39);           // spy skins
  graphics::Color bright_red(251, 44, 0);       // fuse tips
  graphics::Color bright_yellow(243, 255, 83);  // fuse tips
  graphics::Color brown(133, 81, 8);            // fuse
  graphics::Image player(50, 50);
  // Hat
  player.DrawRectangle(15, 3, 18, 6, black);  // outline
  player.DrawRectangle(6, 9, 38, 3, black);   // bottom
  //
  player.DrawRectangle(17, 5, 13, 4, white);  // inside
  // Face
  player.DrawRectangle(30, 12, 3, 18, black);  // right
  player.DrawLine(29, 24, 29, 28, black);      // left face 1
  player.DrawLine(28, 23, 28, 27, black);      // left face 2
  player.DrawLine(27, 22, 27, 26, black);
  player.DrawLine(26, 21, 26, 26, black);
  player.DrawLine(25, 20, 25, 26, black);
  player.DrawLine(24, 19, 24, 23, black);
  player.DrawLine(23, 18, 23, 22, black);
  player.DrawLine(22, 17, 22, 21, black);
  player.DrawLine(21, 16, 21, 20, black);
  player.DrawLine(20, 15, 20, 19, black);
  player.DrawLine(19, 14, 19, 18, black);
  player.DrawLine(18, 13, 18, 17, black);
  player.DrawLine(17, 12, 17, 17, black);
  player.DrawLine(16, 12, 16, 15, black);
  player.DrawLine(15, 12, 15, 14, black);
  //
  player.DrawLine(18, 12, 29, 12, skin);
  player.DrawLine(19, 13, 28, 13, skin);
  player.DrawLine(20, 14, 28, 14, skin);
  player.DrawLine(21, 15, 28, 15, skin);
  player.DrawLine(22, 16, 29, 16, skin);
  player.DrawLine(23, 17, 29, 17, skin);
  player.DrawLine(24, 18, 29, 18, skin);
  player.DrawLine(25, 19, 29, 19, skin);
  player.DrawLine(26, 20, 29, 20, skin);
  player.DrawLine(27, 21, 29, 21, skin);
  player.DrawLine(28, 22, 29, 22, skin);
  player.SetColor(29, 23, skin);
  player.DrawRectangle(23, 13, 3, 3, black);  // left eye
  player.DrawLine(29, 13, 29, 15, black);     // right eye
  // Body
  player.DrawRectangle(25, 27, 2, 23, black);  // right sides
  player.DrawRectangle(17, 18, 2, 32, black);  // left sides
  player.DrawRectangle(19, 29, 6, 2, black);
  player.DrawRectangle(19, 34, 6, 2, black);
  player.DrawRectangle(19, 43, 6, 2, black);
  player.DrawRectangle(19, 48, 6, 2, black);
  player.DrawRectangle(21, 34, 2, 7, black);
  player.DrawRectangle(21, 45, 2, 3, black);
  //
  player.DrawRectangle(19, 36, 2, 7, white);
  player.DrawRectangle(23, 36, 2, 7, white);
  player.DrawRectangle(19, 45, 2, 3, white);
  player.DrawRectangle(23, 45, 2, 3, white);
  player.DrawRectangle(19, 31, 6, 3, gray);
  player.DrawRectangle(19, 24, 6, 5, white);
  player.DrawLine(19, 23, 23, 23, white);
  player.DrawLine(19, 22, 22, 22, white);
  player.DrawLine(19, 21, 21, 21, white);
  player.DrawLine(19, 20, 20, 20, white);
  player.SetColor(19, 19, white);
  // left arm
  player.DrawRectangle(10, 18, 7, 2, black);
  player.DrawRectangle(10, 20, 2, 4, black);
  player.DrawRectangle(8, 24, 9, 2, black);
  player.DrawRectangle(8, 26, 2, 2, black);
  player.DrawRectangle(8, 28, 9, 2, black);
  player.DrawRectangle(10, 30, 2, 3, black);
  player.DrawRectangle(10, 33, 7, 2, black);
  //
  player.DrawRectangle(12, 20, 5, 4, white);
  player.DrawRectangle(10, 26, 7, 2, white);
  player.DrawRectangle(12, 30, 5, 3, skin);
  // Right arm
  player.DrawRectangle(33, 19, 12, 8, black);
  player.DrawLine(35, 27, 40, 27, black);
  player.DrawRectangle(37, 21, 2, 5, white);
  player.DrawRectangle(33, 21, 2, 4, white);
  player.DrawRectangle(41, 21, 2, 4, skin);
  // dynamite
  player.DrawRectangle(41, 27, 3, 3, gray);
  player.DrawRectangle(41, 16, 3, 3, gray);
  player.DrawLine(42, 15, 42, 13, brown);
  player.DrawLine(41, 13, 40, 13, brown);
  player.DrawLine(38, 13, 39, 13, bright_red);
  player.DrawLine(38, 14, 38, 15, bright_red);
  player.DrawLine(36, 16, 38, 16, bright_yellow);
  player.SaveImageBmp("player.bmp");
};
void Player::Draw(graphics::Image &p_image) {
  Player player_sprite;
  player_sprite.Create();
  graphics::Image p_sprite;
  p_sprite.Load("player.bmp");
  // goes through the pixels of the sprite
  for (int row = 0; row < width_; row++) {
    for (int col = 0; col < height_; col++) {
      graphics::Color current = p_sprite.GetColor(row, col);
      p_image.SetColor(x_ + row, y_ + col, current);
    }
  }
}

void Player::Move(const graphics::Image &screen) {
  if (IsOutOfBounds(screen) == true) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
};

void PlayerProjectile::Create() {
  graphics::Image p_projectile(5, 5);
  graphics::Color noir(30, 27, 35);             // use for spy and bomb
  graphics::Color bright_red(251, 44, 0);       // fuse tips
  graphics::Color bright_yellow(243, 255, 83);  // fuse tips
  graphics::Color brown(133, 81, 8);            // fuse
  p_projectile.DrawRectangle(1, 2, 3, 3, noir);
  p_projectile.SetColor(2, 1, brown);
  p_projectile.SetColor(2, 0, bright_yellow);
  p_projectile.SetColor(3, 0, bright_red);
  p_projectile.SaveImageBmp("p_bomb.bmp");
};

void PlayerProjectile::Draw(graphics::Image &pp_image) {
  PlayerProjectile pp_sprite;
  pp_sprite.Create();
  graphics::Image p_bomb;
  p_bomb.Load("p_bomb.bmp");
  // goes through the pixels of the sprite
  for (int row = 0; row < width_; row++) {
    for (int col = 0; col < height_; col++) {
      graphics::Color current = p_bomb.GetColor(row, col);
      pp_image.SetColor(x_ + row, y_ + col, current);
    }
  }
};

void PlayerProjectile::Move(const graphics::Image &screen) {
  SetX(GetX());
  SetY(GetY() + 1);
  if (IsOutOfBounds(screen) == true) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
};
