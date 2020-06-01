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
        ~Engine();

    protected:
    private:
        IrrlichtDevice *device;
        Logger log;
        IVideoDriver* driver;
        ISceneManager* smgr;
        IGUIEnvironment* guienv;
};

#endif /* !ENGINE_HPP_ */
