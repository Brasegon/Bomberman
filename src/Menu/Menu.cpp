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
    config.smgr = config.device->getSceneManager();
    config.guienv = config.device->getGUIEnvironment();
    config.smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
    config.guienv->addButton(rect<s32>(10, 240, 110, 240 + 32), 0, 1,
			L"PLAY", NULL);
    config.guienv->addButton(rect<s32>(10, 240 + 32, 110, 240 + 32 * 2), 0, 2,
			L"QUIT", NULL);
    log.printInfo("Loading Main Menu");
}

void Menu::init(Config &conf) {
    config = conf;
    config.guienv->addButton(rect<s32>(10, 240, 110, 240 + 32), 0, 1,
			L"PLAY", NULL);
    config.guienv->addButton(rect<s32>(10, 240 + 32, 110, 240 + 32 * 2), 0, 2,
			L"QUIT", NULL);
    log.printInfo("Loading Main Menu");
}

const Config &Menu::getUpdateConfig() const
{
    return (config);
}

void Menu::checkClick()
{
    // if (config.event->isButtonClicked())
}
void Menu::update() {

}

void Menu::display()
{
    // std::cout << config.playerList[0]->getPlayerName() << std::endl;
    config.smgr->drawAll();
    config.guienv->drawAll();
}

Menu::~Menu()
{
}
