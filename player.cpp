#include "player.h"

Player::Player(Clicker &clicker) : clicker(clicker) {}

void Player::click() { //функция игрока
    clicker.increment();
}
