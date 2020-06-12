/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "../my.hpp"
#include "../Player/Player.hpp"

class Bomb {
    public:
        Bomb(Player *player);
        ~Bomb();
        const coord2d_t &getCoord();
        Player *getPlayer();
        bool isExploded();
        bool isExplosionEnd();
        irr::scene::IAnimatedMeshSceneNode *node;
        std::vector<irr::scene::ISceneNode *> firenode;

    private:
        Player *player;
        coord2d_t pos;
        std::chrono::time_point<std::chrono::high_resolution_clock> explosionTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> fireTime;
};

#endif /* !BOMB_HPP_ */
