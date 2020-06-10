/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** MyEventReceiver
*/

#include "../Menu/Menu.hpp"

Event::Event()
{
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

bool Event::OnEvent(const SEvent& event)
{
    if (event.EventType == EET_GUI_EVENT) {
        s32 id = event.GUIEvent.Caller->getID();
        switch(event.GUIEvent.EventType) {
            case EGET_BUTTON_CLICKED:
                guiButton.first = id;
                guiButton.second = event.GUIEvent.EventType;
                return true;
            default:
				break;
        }
    }
    // Remember whether each key is down or up
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

    return false;
}

void Event::clear()
{
    guiButton.first = 0;
    guiButton.second = (EGUI_EVENT_TYPE) 0;
}

bool Event::isButtonClicked(irr::s32 buttonId)
{
    if (guiButton.first == buttonId) {
        return true;
    }
    return false;
}

bool Event::IsKeyDown(EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}

Event::~Event()
{
}
