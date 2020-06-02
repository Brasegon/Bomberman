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
}

void Core::launch()
{
    init();
    engine->run();
}

Core::~Core()
{
}
