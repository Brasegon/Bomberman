/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_
#include "../my.hpp"
#include "../Engine/Config.hpp"
#include "../Event/EventMenu.hpp"
#include "../Logger/Logger.hpp"

class IScene {
    public:
        virtual void display() = 0;
        virtual void update() = 0;
        virtual void init(Config &conf) = 0;
        virtual const Config &getUpdateConfig() const = 0;
    protected:
    private:
};

#endif /* !SCENE_HPP_ */
