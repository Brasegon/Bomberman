/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Save
*/

#include "Save.hpp"
#include <fstream>

Save::Save()
{
}

bool Save::saveMap(std::vector<std::string> map, Config &conf)
{
    std::ofstream saveMap("save.txt");

    if (saveMap) {
        for (size_t i = 0; i < conf.playerList.size(); i += 1) {
            saveMap << conf.playerList[i]->getPlayerName() << " " << ((conf.playerList[i]->getIsBot())  ? "1" : "0") << std::endl;
        }
        for (size_t i = 0; i < map.size(); i += 1) {
            saveMap << map[i] << std::endl;
        }
        return true;
    }
    return false;
}

Save::~Save()
{
}
