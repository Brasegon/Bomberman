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

    boxName.push_back(config.guienv->addEditBox(L"Player 1", irr::core::rect<irr::s32>(10, 10, 60, 30)));
    boxName.push_back(config.guienv->addEditBox(L"Player 2", irr::core::rect<irr::s32>(60 + 10, 10, 50 * 2 + 20, 30)));
    boxName.push_back(config.guienv->addEditBox(L"Player 3", irr::core::rect<irr::s32>(10, 30 + 10, 60, 30 * 2)));
    boxName.push_back(config.guienv->addEditBox(L"Player 4", irr::core::rect<irr::s32>(60 + 10, 30 + 10, 50 * 2 + 20, 30 * 2)));
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
