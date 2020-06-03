/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AScene
*/
#include "IScene.hpp"
#include "../my.hpp"
#include "../Engine/Config.hpp"
#include "../Event/EventMenu.hpp"
#include "../Logger/Logger.hpp"
#ifndef ASCENE_HPP_
#define ASCENE_HPP_

class AScene : public IScene {
    public:
        AScene(Config &conf) : config(conf) {
            config.event->clear();
        }
        ~AScene() override = default;

    protected:
        Config config;
    private:
};

#endif /* !ASCENE_HPP_ */
