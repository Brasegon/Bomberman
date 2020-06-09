/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Log
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "../my.hpp"

class Map
{
public:
	Map();
	~Map();
	void OpenMap(std::string path);
private:
protected:
	std::vector<std::string> map;

	enum MapObject {
		Border = '#',
		Player = 'P',
		Destruct = 'D',
		NoDestruct = 'X',
		Powerup = 'U'
	};
};
#endif