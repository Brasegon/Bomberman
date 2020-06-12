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
        saveMap << std::to_string(conf.playerList.size()) << std::endl;
        for (size_t i = 0; i < conf.playerList.size(); i += 1) {
            saveMap << conf.playerList[i]->getPlayerName() << " ";
            saveMap << ((conf.playerList[i]->getIsBot())  ? "1 " : "0 ");
            saveMap << conf.playerList[i]->getCoord().x << " " << conf.playerList[i]->getCoord().y << std::endl;
        }
        for (size_t i = 0; i < map.size(); i += 1) {
            saveMap << map[i] << std::endl;
        }
        return true;
    }
    return false;
}

const std::vector<Player *> Save::getPlayerSave() const 
{
    std::ifstream saveMap("save.txt");
    std::vector<Player *> playerList;
    std::string line;
    if (saveMap) {
        std::getline(saveMap, line);
        int nb = std::stoi(line);
        for (int i = 0; i < nb; i += 1) {
            std::getline(saveMap, line);
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> test;
            while (std::getline(ss, token, ' ')) {
                test.push_back(token);
            }
            bool isBot = (test[1] == "1") ? true : false;
            coord2d_t pos;
            pos.x = std::stoi(test[2]);
            pos.y = std::stoi(test[3]);
            playerList.push_back(new Player(test[0], isBot, i));
            playerList[playerList.size() - 1]->setCoord(pos);
        }

    }
    return playerList;
}

const std::vector<std::string> Save::getMap() const
{   
    std::ifstream saveMap("save.txt");
    std::vector<std::string> map;
    if (saveMap) {
        std::string line;
        std::getline(saveMap, line);
        int nb = std::stoi(line);
        for (int i = 0; std::getline(saveMap, line); i += 1) {
            if (i > nb - 1) {
                map.push_back(line);
                std::cout << line << std::endl;
            }
        }
    }
    return map;

}

Save::~Save()
{
}
