/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Save
*/

#ifndef SAVE_HPP_
#define SAVE_HPP_

#include "../my.hpp"
#include "../Engine/Config.hpp"
#include "../Event/Event.hpp"
#include "../Logger/Logger.hpp"

class Save {
    public:
        Save();
        bool saveMap(std::vector<std::string> map, Config &conf);
        ~Save();

    protected:
    private:
    std::vector<std::string> mapSave;
};

#endif /* !SAVE_HPP_ */
