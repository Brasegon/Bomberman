/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomb::Bomb(Player *_player)
:player(_player), pos(_player->getCoord()), explosionTime(std::chrono::high_resolution_clock().now()+std::chrono::milliseconds(2000))
{
}

Bomb::~Bomb()
{
}

const coord2d_t &Bomb::getCoord()
{
    return pos;
}

Player *Bomb::getPlayer()
{
    return player;
}

bool Bomb::isExploded()
{
    if (std::chrono::high_resolution_clock().now() < explosionTime)
        return false;
    return true;
}
