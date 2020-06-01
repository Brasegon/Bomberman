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
    config.smgr = config.device->getSceneManager();
    config.guienv = config.device->getGUIEnvironment();
    config.smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
}

void Engine::run()
{
    Menu *menu = new Menu(config);
    while(config.device->run()) {
        menu->launch();
    }
}

Engine::~Engine()
{
}
