/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Engine
*/

#include "Engine.hpp"

Engine::Engine(int height, int width, std::wstring title)
{
    config.device = createDevice(video::EDT_SOFTWARE, dimension2d<u32>(height, width), 16, false, false, false, 0);
    config.device->setWindowCaption(title.c_str());
    config.driver = config.device->getVideoDriver();
    config.event = new EventMenu();
    config.device->setEventReceiver(config.event);
}


void Engine::run()
{
    Menu *menu = new Menu(config);
    while(config.device->run()) {
        config.driver->beginScene(true, true, SColor(255, 100, 101, 140));
        menu->display();
        config.driver->endScene();
    }
}

Engine::~Engine()
{
}
