#include <iostream>
#include <memory>
#include <vector>
#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"
#include "stddef.h"

#ifndef GAME_H
#define GAME_H

class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 public:
  Game(int width, int height) : screen_(width, height) {}
  Game() : Game(800, 600) {}

  graphics::Image& GetGameScreen() { return screen_; }
  std::vector<std::unique_ptr<Opponent>>& GetOpponents() { return Op_; }
  std::vector<std::unique_ptr<OpponentProjectile>>& GetOpponentProjectiles() {
    return Opp_;
  }
  std::vector<std::unique_ptr<PlayerProjectile>>& GetPlayerProjectiles() {
    return pp_;
  }
  Player& GetPlayer() { return my_player_; }
  int GetScore() { return score_; }
  bool HasLost() { return lost_; }

  void CreateOpponents();

  void Init();

  void UpdateScreen();

  void Start();

  void MoveGameElements();

  void FilterIntersections();

  void OnAnimationStep() override {
    // count opponents
    int opponent_num = Op_.size();
    if (opponent_num == 0) {
      CreateOpponents();
    }
    MoveGameElements();
    LaunchProjectiles();
    FilterIntersections();
    RemoveInactive();
    UpdateScreen();
    screen_.Flush();
  }

  void LaunchProjectiles();

  void RemoveInactive();

  void OnMouseEvent(const graphics::MouseEvent& object) override;

 private:
  graphics::Image screen_;
  std::vector<std::unique_ptr<Opponent>> Op_;
  std::vector<std::unique_ptr<OpponentProjectile>> Opp_;
  std::vector<std::unique_ptr<PlayerProjectile>> pp_;
  Player my_player_;
  int score_;
  bool lost_;
};

#endif  // GAME_H
