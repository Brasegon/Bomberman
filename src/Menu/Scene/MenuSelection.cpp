/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MenuSelection
*/

#include "MenuSelection.hpp"

MenuSelection::MenuSelection(Config &conf) : AScene(conf)
{
    config = conf;
    config.smgr = config.device->getSceneManager();
    config.guienv = config.device->getGUIEnvironment();
    config.smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

    config.guienv->addButton(rect<s32>(10, 240, 110, 240 + 32), 0, 1,
			L"TEST", NULL);
    log.printInfo("Loading Main Selection");
}

void MenuSelection::init(Config &conf)
{

}

const Config &MenuSelection::getUpdateConfig() const
{
    return (config);
}

ChangeScene MenuSelection::checkClick(ChangeScene change)
{
    return {false, NONE};
}

ChangeScene MenuSelection::update()
{
    ChangeScene change;
    change = checkClick(change);
    return change;
}

void MenuSelection::display()
{
    config.smgr->drawAll();
    config.guienv->drawAll();
}

MenuSelection::~MenuSelection()
{
}
