/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** MyEventReceiver
*/

#ifndef EVENTMENU_HPP_
#define EVENTMENU_HPP_
#include "../my.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class EventMenu : public IEventReceiver {
    public:
        EventMenu();
        virtual bool OnEvent(const SEvent& event);
        bool isButtonClicked(irr::s32 id);
        void clear();
        ~EventMenu();
        bool isActive;
    protected:
    private:
        std::pair<irr::s32, irr::gui::EGUI_EVENT_TYPE> guiButton;
};

#endif /* !EVENTMENU_HPP_ */
