/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#include "Map.hpp"


Map::Map(){}

Map::~Map(){}

void Map::OpenMap(std::string &path)
{
	std::ifstream file(path);
	std::string buffer;

	try {
		if (!file || file.peek() == std::ifstream::traits_type::eof()) {
			throw string("Map is empty");
		}
		while (std::getline(file, buffer))
			map.push_back(buffer);
	}
	catch (Exception ex) {
		std::string errorStr = "[ERROR]" + ex->ToString()->Data();
		MessageBoxW(NULL, errorStr, "", MB_OK);
	}
}

void Map::SortLines()
{
	switch (c) {
		case '#':
			break;
		case 'P':
			break;
		case 'D':
			break;
		case 'X':
			break;
		case 'U';
			break;
		default:
			break;
	}
}

void Map::Load(std::string &path)
{
	OpenMap(path);

	MapObject obj;

	switch (obj) {
		case Border:
			break;
		case Player:
			break;
		case Destruct:
			break;
		case NoDestruct:
			break;
		case PowerUp:
			break;
		default:
			break;
	}

}