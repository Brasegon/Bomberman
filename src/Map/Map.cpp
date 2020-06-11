/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#include "Map.hpp"
#include <exception>


Map::Map(){}

Map::~Map(){}

void Map::OpenMap(const std::string &path)
{
	std::ifstream file(path);
	std::string buffer;

	try {
		if (!file || file.peek() == std::ifstream::traits_type::eof()) {
			throw std::string("Map is empty");
		}
		while (std::getline(file, buffer))
			map.push_back(buffer);
	}
	catch (std::string &ex) {
		std::cerr << "[ERROR] " << ex << std::endl;
	}
}

void Map::LoadMap(scene::ISceneNode* n, std::vector<irr::scene::ISceneNode*> nodeList, Config& conf) {
	Map m;
	m.OpenMap("../assets/Map/map1.txt");
	for (size_t i = 0; i < map.size(); i++) {
		for (size_t j = 0; j < map[i].length(); j++) {
			float xPos = -90 + ((float)(j) * 20);
			float yPos = 60 - ((float)(i) * 20);
			if (map[i][j] != '\n' && map[i][j] != 0) {
				switch (map[i][j]) {
				case '#': // BORDURE DE MAP
					m.noDestruc = true;
					m.wall = true;
					n->setScale(core::vector3df(2, 2, 2));
					n->setMaterialTexture(0, conf.driver->getTexture("../assets/textures/wallNoDestru.bmp"));
					n->setMaterialFlag(video::EMF_LIGHTING, false);
					n->setPosition(core::vector3df(xPos, yPos, 30));
					break;
				case 'P': // PLAYER
					n->setScale(core::vector3df(2, 2, 2));
					n->setMaterialTexture(0, conf.driver->getTexture("../assets/texture/tile.bmp"));
					n->setMaterialFlag(video::EMF_LIGHTING, false);
					n->setPosition(core::vector3df(xPos, yPos, 30));
					break;
				case 'D': // MUR DESTRUCTIBLE
					m.wall = true;
					n->setScale(core::vector3df(2, 2, 2));
					n->setMaterialTexture(0, conf.driver->getTexture("../assets/Map/walldestr.bmp"));
					n->setMaterialFlag(video::EMF_LIGHTING, false);
					n->setPosition(core::vector3df(xPos, yPos, 30));
					break;
				case 'X': // MUR INDESTRUCTIBLE
					m.wall = true;
					m.noDestruc = true;
					n->setScale(core::vector3df(2, 2, 2));
					n->setMaterialTexture(0, conf.driver->getTexture("../assets/Map/wallNoDestru.bmp"));
					n->setMaterialFlag(video::EMF_LIGHTING, false);
					n->setPosition(core::vector3df(xPos, yPos, 30));
					break;
				case 'U': // POWERUP
					n->setScale(core::vector3df(2, 2, 2));
					n->setMaterialTexture(0, conf.driver->getTexture("../assets/Map/tile.bmp"));
					n->setMaterialFlag(video::EMF_LIGHTING, false);
					n->setPosition(core::vector3df(xPos, yPos, 30));
					break;
				default:
					n->setScale(core::vector3df(2, 2, 2));
					n->setMaterialTexture(0, conf.driver->getTexture("../assets/textures/tile.bmp"));
					n->setMaterialFlag(video::EMF_LIGHTING, false);
					n->setPosition(core::vector3df(xPos, yPos, 30));
					break;
				}
			}
		}
	}
}