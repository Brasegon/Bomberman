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
#include "../Logger/Logger.hpp"
#include "IScene.hpp"
class Menu : public IScene {
    public:
        Menu(Config &conf);
        void launch();
        void init(Config &conf);
        const Config &getUpdateConfig() const;
        ~Menu();

    protected:
    private:
        Config config;
        bool isActive;
        EventMenu *event;
        Logger log;
};

#endif /* !MENU_HPP_ */
