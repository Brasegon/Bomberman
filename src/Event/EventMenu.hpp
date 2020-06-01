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
        EventMenu(Config &conf);
        virtual bool OnEvent(const SEvent& event);
        ~EventMenu();
        bool isActive;
    protected:
    private:
        Config config;
};

#endif /* !EVENTMENU_HPP_ */
