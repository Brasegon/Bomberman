/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerUp
*/

#include "PowerUp.hpp"

PowerUp::PowerUp()
{
    despawnTime = std::chrono::high_resolution_clock().now()+std::chrono::milliseconds(5000);
}

PowerUp::~PowerUp()
{
}

const coord2d_t &PowerUp::getCoord() const
{
    return coord;
}

void PowerUp::setCoord(coord2d_t &_coord)
{
    coord = _coord;
}

const PowerUpType &PowerUp::getType() const
{
    return type;
}

void PowerUp::setType(PowerUpType _type)
{
    type = _type;
}

bool PowerUp::isDespawn()
{
    if (std::chrono::high_resolution_clock().now() > despawnTime)
        return true;
    return false;
}

