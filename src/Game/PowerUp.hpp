/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerUp
*/

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "../my.hpp"
#include "../Player/Player.hpp"

class PowerUp {
    public:
        PowerUp();
        ~PowerUp();
        const coord2d_t &getCoord() const;
        void setCoord(coord2d_t &_coord);
        const PowerUpType &getType() const;
        void setType(PowerUpType _type);
        bool isDespawn();
        irr::scene::ISceneNode * node;

    private:
        PowerUpType type;
        coord2d_t coord;
        std::chrono::time_point<std::chrono::high_resolution_clock> despawnTime;
};

#endif /* !POWERUP_HPP_ */
