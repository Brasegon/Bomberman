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
#include "../Event/Event.hpp"
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Setting {
    public:
        Setting() {}
        ~Setting() {}
        sf::Music *music;
};

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
        Event *event;
        Setting setting;
        bool newGame;
    protected:
    private:
};

#endif /* !CONFIG_HPP_ */
