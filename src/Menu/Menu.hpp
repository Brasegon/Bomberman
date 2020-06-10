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
#include "../Event/Event.hpp"
#include "../Logger/Logger.hpp"
#include "AScene.hpp"
class Menu : public AScene {
    public:
        Menu(Config &conf);
        void display() override;
        ChangeScene update() override;
        void init(Config &conf);
        const Config &getUpdateConfig() const override;
        ~Menu() override;

    protected:
    private:
        ChangeScene checkClick(ChangeScene change);
        bool isActive;
        Logger log;
        sf::Music *music;
        ITexture *background;
        video::ITexture* logo;
};

#endif /* !MENU_HPP_ */
