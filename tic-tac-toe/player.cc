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

std::string Player::get_name(bool full) const {
  if (full)
    return name;

  std::string first_name;
  for (int i = 0; i < name.length(); i++) {
    if (name[i] == ' ')
      return first_name;
    else
      first_name += name[i];
  }

  return name;
}

void Player::set_name(std::string n) {
  name = n;
}
