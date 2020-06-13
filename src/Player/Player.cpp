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
:playerName(name), isBot(bot), playerNb(nb), keys(keybinds[nb]), pos({0,0}), buff({0, 0, 250, false})
{
    std::string iaOrNot = (isBot) ? "IA" : "Player";
    log.printInfo("Initialisation du joueur " + playerName + "(" + iaOrNot + ")" + " Key Number : " + std::to_string(nb));
    start = std::chrono::high_resolution_clock().now();
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

void Player::initCoord(const std::vector<std::string> &map)
{
    size_t Pcount = 0;
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 'P') {
                if (Pcount >= playerNb) {
                    pos = {i, j};
                    return;
                }
                Pcount++;
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

bool Player::MoveClock() {
    end = std::chrono::high_resolution_clock().now();
    if (end-start >= std::chrono::milliseconds(buff.SpeedUp)) {
        start = std::chrono::high_resolution_clock().now();
        return true;
    }
    return false;
}

const playerBuff_t &Player::getBuff() const
{
    return buff;
}

void Player::addBuffBombUp()
{
    if (buff.BombUp <= 5)
        buff.BombUp++;
}

void Player::addBuffFireUp()
{
    if (buff.FireUp <= 3)
        buff.FireUp++;
}

void Player::addBuffSpeedUp()
{
    if (buff.SpeedUp >= 150) {
        buff.SpeedUp -= 25;
    }
}

void Player::addBuffWallPass()
{
    buff.WallPass = true;
}

void Player::addBuff(PowerUpType type)
{
    if (type == BOMBUP) {
        addBuffBombUp();
    }
    if (type == FIREUP) {
        addBuffFireUp();
    }
    if (type == SPEEDUP) {
        addBuffSpeedUp();
    }
    if (type == WALLPASS) {
        addBuffWallPass();
    }
}

Player::~Player()
{
}

bool operator==(coord2d_t coord1, coord2d_t coord2) {
    if (coord1.x == coord2.x && coord1.y == coord2.y)
        return true;
    return false;
}