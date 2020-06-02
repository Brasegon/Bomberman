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
    _scene = new Menu(config);
}

void Engine::update() 
{
    if (_scene->update().first && _scene->update().second != NONE) {
        config.event->clear();
        selectScene(config, _scene->update().second);
    }
}

void Engine::selectScene(Config &conf, SceneType sceneId)
{
    delete _scene;
    switch (sceneId)
    {
    case MAIN_MENU/* constant-expression */:
        _scene = new Menu(conf);
        break;
    case MAIN_SELECTION:
        break;
    default:
        break;
    }
}

void Engine::display()
{
    config.driver->beginScene(true, true, SColor(255, 100, 101, 140));
    _scene->display();
    config.driver->endScene();
}

void Engine::run()
{
    while(config.device->run()) {
        display();
        update();
    }
}

Engine::~Engine()
{
}
