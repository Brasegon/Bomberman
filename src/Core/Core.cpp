/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Core
*/

#include "Core.hpp"

Core::Core()
{
}

void Core::init()
{
    engine = new Engine(1280, 720, L"Indie Studio");
    playerList.push_back(new Player("Player 1", false));
    playerList.push_back(new Player("Player 2", false));
    playerList.push_back(new Player("Player 3", false));
    playerList.push_back(new Player("Player 4", false));
}

void Core::launch()
{
    init();
    engine->run();
}

Core::~Core()
{
}
