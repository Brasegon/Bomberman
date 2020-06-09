/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** my
*/

#ifndef MY_HPP_
#define MY_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include "../include/irrlicht/irrlicht.h"
#include "../include/SFML/Audio.hpp"
#include "../include/SFML/System.hpp"
#include <codecvt>
#include <locale>
#include <chrono>
#include <thread>
#include <window>

enum SceneType {
    NONE = -1,
    MAIN_MENU,
    MAIN_SELECTION,
    GAME,
};

using ChangeScene = std::pair<bool, SceneType>;
#endif /* !MY_HPP_ */
