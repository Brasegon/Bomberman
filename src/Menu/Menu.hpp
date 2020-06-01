/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_
#include "../my.hpp"
#include "../Engine/Config.hpp"
#include "../Event/EventMenu.hpp"
class Menu {
    public:
        Menu(Config &conf);
        void launch();
        void init(Config &conf);
        ~Menu();

    protected:
    private:
        Config config;
        bool isActive;
        EventMenu *event;
};

#endif /* !MENU_HPP_ */
