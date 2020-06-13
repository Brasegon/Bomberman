/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** End
*/

#include "End.hpp"

End::End(Config &conf) : AScene(conf)
{
    config = conf;
    config.smgr = config.device->getSceneManager();
    config.guienv = config.device->getGUIEnvironment();
    config.smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
    background = config.driver->getTexture("./assets/textures/endgame.png");

    addButton(650 / 2 - 50, 100, 100, 32, L"MENU", 1);
    addButton(650 / 2 - 50, 100 + 80, 100, 32, L"QUIT", 2);
    addButton(650 / 2 - 50, 100 + 40, 100, 32, L"REPLAY", 3);

    log.printInfo("Loading End Game");
}

End::~End()
{
    log.printInfo("Close End Game");
    config.smgr->clear();
    config.guienv->clear();
    config.driver->clearZBuffer();
}

ChangeScene End::update()
{
    ChangeScene change;
    change = checkClick(change);
    return change;
}

ChangeScene End::checkClick(ChangeScene change)
{
    if (config.event->isButtonClicked(1)) {
        return {true, MAIN_MENU};
    }
    if (config.event->isButtonClicked(2)) {
        std::exit(0);
    }
    if (config.event->isButtonClicked(3)) {
        return {true, MAIN_SELECTION};
    }
    return {false, NONE};
}


const Config &End::getUpdateConfig() const
{
    return (config);
}

void End::display()
{
    config.driver->draw2DImage(background, core::position2d<s32>(0,0),
                core::rect<s32>(0,0,650,366), 0,
                video::SColor(255,255,255,255), true);
    config.smgr->drawAll();
    config.guienv->drawAll();
}