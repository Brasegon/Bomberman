/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Config
*/

#ifndef CONFIG_HPP_
#define CONFIG_HPP_
#include "../my.hpp"
#include "../Logger/Logger.hpp"
#include "../Player/Player.hpp"
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Config {
    public:
        Config() {}
        ~Config() {}
        IrrlichtDevice *device;
        Logger log;
        IVideoDriver* driver;
        ISceneManager* smgr;
        IGUIEnvironment* guienv;
        std::vector<Player *> playerList;
    protected:
    private:
};

#endif /* !CONFIG_HPP_ */
