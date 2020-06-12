/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(Config &conf) : AScene(conf)
{
    isActive = true;
    config = conf;
    config.smgr = config.device->getSceneManager();
    config.guienv = config.device->getGUIEnvironment();
    config.smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
    background = config.driver->getTexture("./assets/textures/background.jpg");

    config.setting.music = new sf::Music();
    if (!config.setting.music->openFromFile("assets/music.ogg")) {
        exit(84);
    }
    config.setting.music->setVolume(50);
    config.setting.music->play();

    logo = config.driver->getTexture("./assets/textures/logo.png");

    addButton(1280 / 2 - 50, 350, 100, 32, L"NEW GAME", 1);
    addButton(1280 / 2 - 50, 350 + 80, 100, 32, L"QUIT", 2);
    addButton(1280 / 2 - 50, 350 + 40, 100, 32, L"LOAD GAME", 3);
    
    log.printInfo("Loading Main Menu");
}

void Menu::init(Config &conf) {
    config = conf;
    config.guienv->addButton(rect<s32>(1280 / 2 - 105, 240, 110, 240 + 32), 0, 1,
			L"PLAY", NULL);
    config.guienv->addButton(rect<s32>(1280 / 2 - 105, 240 + 32, 110, 240 + 32 * 2), 0, 2,
			L"QUIT", NULL);
    log.printInfo("Loading Main Menu");
}

const Config &Menu::getUpdateConfig() const
{
    return (config);
}

ChangeScene Menu::checkClick(ChangeScene change)
{
    if (config.event->isButtonClicked(1)) {
        return {true, MAIN_SELECTION};
    }
    if (config.event->isButtonClicked(2)) {
        std::exit(0);
    }
    if (config.event->isButtonClicked(3)) {
        config.setting.music->stop();
        config.newGame = false;
        return {true, GAME};
    }
    return {false, NONE};
}

ChangeScene Menu::update()
{
    ChangeScene change;
    change = checkClick(change);
    return change;
}

void Menu::display()
{
    config.driver->draw2DImage(background, core::position2d<s32>(0,0),
				core::rect<s32>(0,0,1280,720), 0,
				video::SColor(255,255,255,255), true);
    config.driver->draw2DImage(logo, core::position2d<s32>(1280 / 2 - 517 / 2, 10),
				core::rect<s32>(0,0, 1033,620), 0,
				video::SColor(255,255,255,255), true);
    config.smgr->drawAll();
    config.guienv->drawAll();
}

Menu::~Menu()
{
    log.printInfo("Close Main Menu");
    config.smgr->clear();
    config.guienv->clear();
    config.driver->clearZBuffer();
}
