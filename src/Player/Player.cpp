/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Player
*/

#include "Player.hpp"

static keybind_t keybinds[4] = {
    {irr::KEY_KEY_Z,irr::KEY_KEY_S,irr::KEY_KEY_Q,irr::KEY_KEY_D, irr::KEY_KEY_E},
    {irr::KEY_UP,irr::KEY_DOWN,irr::KEY_LEFT,irr::KEY_RIGHT, irr::KEY_RSHIFT},
    {irr::KEY_KEY_Y,irr::KEY_KEY_H,irr::KEY_KEY_G,irr::KEY_KEY_J, irr::KEY_KEY_U},
    {irr::KEY_KEY_O,irr::KEY_KEY_L,irr::KEY_KEY_K,irr::KEY_KEY_M, irr::KEY_KEY_P},
};

Player::Player(const std::string &name, bool bot, size_t nb)
:playerName(name), isBot(bot), playerNb(nb), keys(keybinds[nb]), pos({0,0})
{
    std::string iaOrNot = (isBot) ? "IA" : "Player";
    log.printInfo("Initialisation du joueur " + playerName + "(" + iaOrNot + ")");
}

const std::string &Player::getPlayerName() const
{
    return (playerName);
}

void Player::setPlayerName(std::string name)
{
    playerName = name;
}

bool Player::getIsBot() const
{
    return isBot;
}

keybind_t Player::getKeys() const
{
    return keys;
}

void Player::initCoord(std::vector<std::string> map)
{
    size_t Pcount = 0;
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 'P') {
                Pcount++;
                if (Pcount == playerNb) {
                    pos = {i, j};
                    return;
                }
            }
        }
    }
}

const coord2d_t &Player::getCoord() const
{
    return pos;
}

void Player::setCoord(coord2d_t _pos) {
    pos = _pos;
}

Player::~Player()
{
}
