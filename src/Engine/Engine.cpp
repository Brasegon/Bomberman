/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Engine
*/

#include "Engine.hpp"

Engine::Engine(int height, int width, std::wstring title)
{
    device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(height, width), 16, false, false, false, 0);
    device->setWindowCaption(title.c_str());
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
    smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
}

void Engine::run()
{
    while(device->run()) {
        //driver->beginScene(true, true, SColor(255, 100, 101, 140));
    }
}

Engine::~Engine()
{
}
