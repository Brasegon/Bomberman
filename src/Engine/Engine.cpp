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
    config.event = new Event();
    config.device->setEventReceiver(config.event);
    _scene = new SceneIntro(config);
}

void Engine::update() 
{
    if (_scene->update().first && _scene->update().second != NONE) {
        selectScene(config, _scene->update().second);
    }
}

void Engine::selectScene(Config &conf, SceneType sceneId)
{
    conf = _scene->getUpdateConfig();
    delete _scene;
    switch (sceneId)
    {
    case MAIN_MENU/* constant-expression */:
        _scene = new Menu(conf);
        oldScene = sceneId;
        break;
    case MAIN_SELECTION:
        _scene = new MenuSelection(conf);
        oldScene = sceneId;
        break;
    case GAME:
        _scene = new GameScene(conf);
        break;
    case END:
        _scene = new End(conf);
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
