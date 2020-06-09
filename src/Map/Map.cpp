/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(){}

Map::~Map(){}

void Map::OpenMap(std::string path)
{
	std::ifstream mapBuff(path);
	std::string buffer;

	while (std::getline(mapBuff, buffer))
		map.push_back(buffer);
}

