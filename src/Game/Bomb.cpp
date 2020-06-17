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
    node = NULL;
    fireTime = explosionTime+std::chrono::milliseconds(500);
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
void Bomb::playSound()
{
    sf::SoundBuffer *buffer = new sf::SoundBuffer();
    sf::Sound *sound = new sf::Sound();

    // if (buffer->loadFromFile("./assets/boom.ogg"))
    //     exit(84);
    sound->setBuffer(*buffer);
    sound->play();
}
bool Bomb::isExploded()
{
    if (std::chrono::high_resolution_clock().now() < explosionTime)
        return false;
    return true;
}

bool Bomb::isExplosionEnd()
{
    if (std::chrono::high_resolution_clock().now() < fireTime)
        return false;
    return true;
}
