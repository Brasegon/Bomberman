/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Core
*/
#include "../my.hpp"
#include "../Player/Player.hpp"

#ifndef CORE_HPP_
#define CORE_HPP_
class Core {
    public:
        Core();
        void launch();
        void init();
        ~Core();

    protected:
    private:
        std::vector<Player *> playerList;
};

#endif /* !CORE_HPP_ */
