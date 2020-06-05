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
        virtual ChangeScene update() = 0;
        virtual const Config &getUpdateConfig() const = 0;
        virtual ~IScene() = default;
    protected:
    private:
};

#endif /* !SCENE_HPP_ */
