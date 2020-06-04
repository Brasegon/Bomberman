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
    boxButton.push_back(addButton(70, 10, 50, 20, L"Player", GUI_CHOOSE_PLAYER_ONE));
    boxName.push_back(config.guienv->addEditBox(L"Player 2", irr::core::rect<irr::s32>(10, 40, 60, 30 + 30)));
    boxButton.push_back(addButton(70, 40, 50, 20, L"Player", GUI_CHOOSE_PLAYER_TWO));
    // boxName.push_back(config.guienv->addEditBox(L"Player 2", irr::core::rect<irr::s32>(60 + 10, 10, 50 * 2 + 20, 30)));
    // boxName.push_back(config.guienv->addEditBox(L"Player 3", irr::core::rect<irr::s32>(10, 30 + 10, 60, 30 * 2)));
    // boxName.push_back(config.guienv->addEditBox(L"Player 4", irr::core::rect<irr::s32>(60 + 10, 30 + 10, 50 * 2 + 20, 30 * 2)));
    boxName[0]->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER);
    boxName[1]->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER);
    // boxName[2]->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER);
    // boxName[3]->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER);
    launchButton = addButton(10 , 600, 60, 30, L"Launch Game", 1);
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
    for (uint64_t i = 2, z = 0 ; z < boxButton.size(); i += 1, z += 1)
    if (config.event->isButtonClicked(i)) {
        std::string playerBot = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes((boxButton[z]->getText()));
        if (playerBot == "Player") {
            boxButton[z]->setText(L"IA");
        } else if (playerBot == "IA") {
            boxButton[z]->setText(L"Player");
        }
        config.event->clear();
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
    config.smgr->drawAll();
    config.guienv->drawAll();
}

MenuSelection::~MenuSelection()
{
    log.printInfo("Close Main Selection");
    config.smgr->clear();
    config.guienv->clear();
    config.driver->clearZBuffer();
}
