/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** MyEventReceiver
*/

#include "../Menu/Menu.hpp"

EventMenu::EventMenu()
{
}

bool EventMenu::OnEvent(const SEvent& event)
{
    if (event.EventType == EET_GUI_EVENT) {
        s32 id = event.GUIEvent.Caller->getID();
        switch(event.GUIEvent.EventType) {
            case EGET_BUTTON_CLICKED:
                guiButton.first = id;
                guiButton.second = event.GUIEvent.EventType;
            default:
				break;
        }
    }
    return false;
}

void EventMenu::clear()
{
    guiButton.first = 0;
    guiButton.second = (EGUI_EVENT_TYPE) 0;
}

bool EventMenu::isButtonClicked(irr::s32 buttonId)
{
    if (guiButton.first == buttonId) {
        return true;
    }
    return false;
}

EventMenu::~EventMenu()
{
}
