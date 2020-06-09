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
    background = config.driver->getTexture("./assets/textures/backgroundSelection.jpg");
    initGui();

    log.printInfo("Loading Main Selection");
}

void MenuSelection::initGui()
{
    boxName.push_back(addEditBox(10, 10, 50, 20, L"Player1"));
    boxButton.push_back(addButton(70, 10, 50, 20, L"Player", GUI_CHOOSE_PLAYER_ONE));

    boxName.push_back(addEditBox(10, 40, 50, 20, L"Player2"));
    boxButton.push_back(addButton(70, 40, 50, 20, L"IA", GUI_CHOOSE_PLAYER_TWO));

    boxName.push_back(addEditBox(10, 70, 50, 20, L"Player3"));
    boxButton.push_back(addButton(70, 70, 50, 20, L"IA", GUI_CHOOSE_PLAYER_THREE));

    boxName.push_back(addEditBox(10, 100, 50, 20, L"Player4"));
    boxButton.push_back(addButton(70, 100, 50, 20, L"IA", GUI_CHOOSE_PLAYER_FOUR));

    boxName[0]->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER);
    boxName[1]->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER);
    boxName[2]->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER);
    boxName[3]->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER);

    launchButton = addButton(10 , 600, 60, 30, L"Launch Game", 1);
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
    std::string playerName;
    std::string playerBot;

    if (config.event->isButtonClicked(1)) {
        for (uint64_t i = 0; i < boxName.size() && config.playerList.size() < boxButton.size(); i += 1) {
            playerName = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes((boxName[i]->getText()));
            playerBot = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes((boxButton[i]->getText()));
            bool isBot = (playerBot == "Player") ? false : true;
            config.playerList.push_back(new Player(playerName, isBot));
        }
        return {true, MAIN_MENU};
    }

    for (uint64_t i = 2, z = 0 ; z < boxButton.size(); i += 1, z += 1) {
        if (config.event->isButtonClicked(i)) {
            std::string playerBot = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes((boxButton[z]->getText()));
            if (playerBot == "Player") {
                boxButton[z]->setText(L"IA");
            } else if (playerBot == "IA") {
                boxButton[z]->setText(L"Player");
            }
            config.event->clear();
        }
    }
    
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
    config.driver->draw2DImage(background, core::position2d<s32>(0,0),
				core::rect<s32>(0,0,1280,720), 0,
				video::SColor(255,255,255,255), true);
    config.smgr->drawAll();
    config.guienv->drawAll();
}

MenuSelection::~MenuSelection()
{
    log.printInfo("Close Main Selection");
    config.setting.music->stop();
    config.smgr->clear();
    config.guienv->clear();
    config.driver->clearZBuffer();
}
