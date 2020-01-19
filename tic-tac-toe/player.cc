#include "player.h"

Player::Player() {
  wins = 0, losses = 0, draws = 0;
  name = "";
}

int Player::get_wins() const {
  return wins;
}

int Player::get_losses() const {
  return losses;
}

int Player::get_draws() const {
  return draws;
}

void Player::add_win() {
  wins++;
}

void Player::add_loss() {
  losses++;
}

void Player::add_draw() {
  draws++;
}

std::string Player::get_name() const {
  return name;
}

void Player::set_name(std::string n) {
  name = n;
}
