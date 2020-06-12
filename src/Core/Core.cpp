/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Core
*/

#include "Core.hpp"

Core::Core()
{
    engine = new Engine(1280, 720, L"Indie Studio");
}

void Core::launch()
{
    engine->run();
}

Core::~Core()
{
    delete engine;
}
