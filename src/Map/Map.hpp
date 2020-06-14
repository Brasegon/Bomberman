/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Log
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "../my.hpp"
#include "../Game/GameScene.hpp"

class Map
{
public:
	Map();
	~Map();
	void OpenMap(const std::string &path);
	void LoadMap(scene::ISceneNode* n, std::vector<irr::scene::ISceneNode*> nodeList, Config& conf);
	std::vector<std::string> GenMap(int xLength, int yLength);
private:
protected:
	bool noDestruc = false;
	bool wall = false;
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