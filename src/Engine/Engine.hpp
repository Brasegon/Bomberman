/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_
#include "../my.hpp"
#include "../Logger/Logger.hpp"
#include "Config.hpp"
#include "../Menu/Menu.hpp"
#include "../Menu/Scene/MenuSelection.hpp"
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
class Engine {
    public:
        Engine(int height, int width, std::wstring title);
        void run();
        void display();
        void update();
        void selectScene(Config &conf, SceneType sceneId);
        ~Engine();

    protected:
    private:
        Config config;
        AScene *_scene;
        SceneType oldScene;
};

#endif /* !ENGINE_HPP_ */
