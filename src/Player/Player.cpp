/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(const std::string &name, bool bot) : playerName(name), isBot(bot)
{
    log.printInfo("Initialisation du joueur " + playerName);
}

const std::string &Player::getPlayerName() const
{
    return (playerName);
}

void Player::setPlayerName(std::string name)
{
    playerName = name;
}

Player::~Player()
{
}
