#include "game.h"
#include <iostream>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "stddef.h"

void Game::CreateOpponents() {
  // create opponent object
  std::unique_ptr<Opponent> my_opponent;
  my_opponent = std::make_unique<Opponent>(100, 50);
  // add to the Op vector
  Op_.push_back(std::move(my_opponent));
};

void Game::Init() {
  // create player
  my_player_.SetX(100);
  my_player_.SetY(250);
  screen_.AddMouseEventListener(*this);
  screen_.AddAnimationEventListener(*this);
};

void Game::UpdateScreen() {
  // draw a rectangle that covers the entire game screen
  // only draw the elements if they are active
  // Game(int width, int height) : screen_(width, height) {}
  // Game() : Game(800, 600) {}
  screen_.DrawText(0, 0, "Score: " + std::to_string(GetScore()), 35,
                   graphics::Color(255, 255, 255));
  if (lost_ == true) {
    screen_.DrawText(235, 250, "GAME OVER", 60, graphics::Color(255, 255, 255));
  }
  for (int i = 0; i < Op_.size(); i++) {
    // check active
    if (Op_[i]->GetIsActive() == true) {
      Op_[i]->Draw(screen_);
    }
  }
  for (int i = 0; i < Opp_.size(); i++) {
    if (Opp_[i]->GetIsActive() == true) {
      Opp_[i]->Draw(screen_);
    }
  }
  for (int i = 0; i < pp_.size(); i++) {
    if (pp_[i]->GetIsActive() == true) {
      pp_[i]->Draw(screen_);
    }
  }
  if (my_player_.GetIsActive() == true) {
    my_player_.Draw(screen_);
  }
};

void Game::Start() { screen_.ShowUntilClosed(); };

void Game::MoveGameElements() {
  // go through each element in the vectors
  for (int i = 0; i < Op_.size(); i++) {
    if (Op_[i]->GetIsActive() == true) {
      Op_[i]->Move(screen_);
      // if active(true) use void Move(graphics::Image &screen)
    }
  }
  for (int i = 0; i < Opp_.size(); i++) {
    if (Opp_[i]->GetIsActive() == true) {
      Opp_[i]->Move(screen_);
    }
  }
  for (int i = 0; i < pp_.size(); i++) {
    if (pp_[i]->GetIsActive() == true) {
      pp_[i]->Move(screen_);
    }
  }
};

void Game::FilterIntersections() {
  // if the opponents intersect with the player - deactivate
  for (int i = 0; i < Op_.size(); i++) {
    if (my_player_.IntersectsWith(Op_[i].get()) == true) {
      my_player_.SetIsActive(false);
      Op_[i]->SetIsActive(false);
      lost_ = true;
    }
  }
  // if the opponent projectiles intersect with players -deactivate
  for (int i = 0; i < Opp_.size(); i++) {
    if (my_player_.IntersectsWith(Opp_[i].get()) == true) {
      my_player_.SetIsActive(false);
      Opp_[i]->SetIsActive(false);
      lost_ = true;
    }
  }
  // if the player projectiles intersect with opponent -deactivate
  // go through everything in both their vectors
  for (int i = 0; i < pp_.size(); i++) {
    for (int j = 0; j < Op_.size(); j++) {
      if (pp_[i]->IntersectsWith(Op_[j].get()) == true) {
        Op_[j]->SetIsActive(false);
        pp_[i]->SetIsActive(false);
        if (my_player_.GetIsActive() == true) {
          score_ = score_ + 1;
        }
      }
    }
  }
};

void Game::LaunchProjectiles() {
  for (int i = 0; i < Op_.size(); i++) {
    std::unique_ptr<OpponentProjectile> projectile;
    projectile = Op_[i]->LaunchProjectile();
    if (projectile != nullptr) {
      Opp_.push_back(std::move(projectile));
    }
  }
};

void Game::RemoveInactive() {
  for (int i = Op_.size() - 1; i >= 0; i--) {
    if (Op_[i]->GetIsActive() == false) {
      Op_.erase(Op_.begin() + i);
    }
  }
  for (int i = Opp_.size() - 1; i >= 0; i--) {
    if (Opp_[i]->GetIsActive() == false) {
      Opp_.erase(Opp_.begin() + i);
    }
  }
  for (int i = pp_.size() - 1; i >= 0; i--) {
    if (pp_[i]->GetIsActive() == false) {
      pp_.erase(pp_.begin() + i);
    }
  }
}

void Game::OnMouseEvent(const graphics::MouseEvent &object) {
  if (object.GetMouseAction() == graphics::MouseAction::kMoved ||
      object.GetMouseAction() == graphics::MouseAction::kDragged) {
    // save the original values for later
    // check if it is within bounds
    if (object.GetX() >= 0 && object.GetX() < screen_.GetWidth()) {
      // my_player_.SetX() needs a corner
      // object x and y should be the middle
      // player size is 50 (draw it out)
      my_player_.SetX(object.GetX() - 25);
    }
    if (object.GetY() >= 0 && object.GetY() < screen_.GetHeight()) {
      my_player_.SetY(object.GetY() - 25);
    }
    std::unique_ptr<PlayerProjectile> click;
    click = std::make_unique<PlayerProjectile>(my_player_.GetX(),
                                               my_player_.GetY());
    pp_.push_back(std::move(click));
  }
};
