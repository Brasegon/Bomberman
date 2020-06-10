/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** MyEventReceiver
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_
#include "../my.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Event : public IEventReceiver {
    public:
        Event();
        virtual bool OnEvent(const SEvent& event);
        bool isButtonClicked(irr::s32 id);
        void clear();
        // This is used to check whether a key is being held down
        virtual bool IsKeyDown(EKEY_CODE keyCode) const;
        ~Event();
    private:
        std::pair<irr::s32, irr::gui::EGUI_EVENT_TYPE> guiButton;

        // We use this array to store the current state of each key
        bool KeyIsDown[KEY_KEY_CODES_COUNT];

        bool isActive;
};

#endif /* !EVENT_HPP_ */
