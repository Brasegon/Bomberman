/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Player
*/

#include "../my.hpp"
#include "../Logger/Logger.hpp"
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

class Player {
    public:
        Player(const std::string &name, bool bot);
        const std::string &getPlayerName() const;
        void setPlayerName(std::string name);
        ~Player();

    protected:
    private:
        std::string playerName;
        bool isBot;
        Logger log;
};

#endif /* !PLAYER_HPP_ */
