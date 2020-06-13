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

enum playerAction {
    NOACTION,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    DROP,
};

typedef struct coord2d_s {
    size_t y;
    size_t x;
} coord2d_t;

typedef struct playerBuff_s {
    unsigned int BombUp;
    unsigned int FireUp;
    unsigned int SpeedUp;
    bool WallPass;
} playerBuff_t;

typedef struct keybind_s {
    irr::EKEY_CODE up;
    irr::EKEY_CODE down;
    irr::EKEY_CODE left;
    irr::EKEY_CODE right;
    irr::EKEY_CODE drop;
} keybind_t;


enum PowerUpType
{
    BOMBUP,
    FIREUP,
    SPEEDUP,
    WALLPASS,
};

class Player {
    public:
        Player(const std::string &name, bool bot, size_t nb);
        const std::string &getPlayerName() const;
        void setPlayerName(std::string name);
        bool getIsBot() const;
        keybind_t getKeys() const;
        void initCoord(const std::vector<std::string> &map);
        const coord2d_t &getCoord() const;
        void setCoord(coord2d_t pos);
        irr::scene::ISceneNode *node;
        bool MoveClock();
        const playerBuff_t &getBuff() const;
        void addBuffBombUp();
        void addBuffFireUp();
        void addBuffSpeedUp();
        void addBuffWallPass();
        void addBuff(PowerUpType);
        ~Player();

    protected:
    private:
        std::string playerName;
        bool isBot;
        size_t playerNb;
        keybind_t keys;
        Logger log;
        coord2d_t pos;
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> end;
        playerBuff_t buff;
};

bool operator==(coord2d_t coord1, coord2d_t coord2);
#endif /* !PLAYER_HPP_ */
