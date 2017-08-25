#include "AI.h"

Player::Player()
{
    player = true;
}

void Player::setPlayer(bool newPlayer) {
    player = newPlayer;
}

bool Player::getPlayer() {
    return player;
}
