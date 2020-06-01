/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(Config &conf)
{
    isActive = true;
    config = conf;
    config.guienv->addButton(rect<s32>(10, 240, 110, 240 + 32), 0, 1,
			L"PLAY", NULL);
    config.guienv->addButton(rect<s32>(10, 240 + 32, 110, 240 + 32 * 2), 0, 2,
			L"QUIT", NULL);
    
    event = new EventMenu(config);
    config.device->setEventReceiver(event);
}

void Menu::init(Config &conf) {
    config = conf;
    config.guienv->addButton(rect<s32>(10, 240, 110, 240 + 32), 0, 1,
			L"PLAY", NULL);
    config.guienv->addButton(rect<s32>(10, 240 + 32, 110, 240 + 32 * 2), 0, 2,
			L"QUIT", NULL);
    
    event = new EventMenu(config);
    config.device->setEventReceiver(event);
}

void Menu::launch()
{
    config.driver->beginScene(true, true, SColor(255, 100, 101, 140));
    config.smgr->drawAll();
    config.guienv->drawAll();
    config.driver->endScene();
}

Menu::~Menu()
{
}
