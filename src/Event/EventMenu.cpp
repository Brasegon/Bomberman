/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** MyEventReceiver
*/

#include "../Menu/Menu.hpp"

EventMenu::EventMenu(Config &conf)
{
    config = conf;
}

bool EventMenu::OnEvent(const SEvent& event)
{
    if (event.EventType == EET_GUI_EVENT) {
        s32 id = event.GUIEvent.Caller->getID();
        switch(event.GUIEvent.EventType) {
            case EGET_BUTTON_CLICKED:
                switch (id) {
                case 1:
                    config.guienv->clear();
                    return (true);
                case 2:
                    config.device->closeDevice();
                    return (true);
                
                default:
                    break;
                }
            default:
				break;
        }
    }
    return false;
}

EventMenu::~EventMenu()
{
}
