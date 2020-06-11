/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameScene
*/

#include "GameScene.hpp"

GameScene::GameScene(Config &conf) : AScene(conf)
{
    config.smgr = config.device->getSceneManager();
    config.guienv = config.device->getGUIEnvironment();
    map = {
        "###############",
        "#P           P#",
        "#             #",
        "#             #",
        "#             #",
        "#             #",
        "#             #",
        "#             #",
        "#P           P#",
        "###############",
    };
    for (size_t i = 0; i < config.playerList.size(); i++) {
        config.playerList[i]->initCoord(map);
        config.log.printInfo(std::to_string(i)+" {"+std::to_string(config.playerList[i]->getCoord().y)+" , "+std::to_string(config.playerList[i]->getCoord().x)+"}");
        config.playerList[i]->node = config.smgr->addSphereSceneNode();
        if (config.playerList[i]->node) {
            float y = 60 - ((float)(config.playerList[i]->getCoord().y) * 20);
            float x = -90 + ((float)(config.playerList[i]->getCoord().x) * 20);
            config.log.printInfo("Création du model du joueur 1");
            config.playerList[i]->node->setPosition(core::vector3df(x, y,30));
            config.playerList[i]->node->setMaterialFlag(video::EMF_LIGHTING, false);
        }
    }
    config.smgr->addCameraSceneNode(0, vector3df(0, 0, -200), vector3df(0, 0, 0));
}

GameScene::~GameScene()
{
}

void GameScene::display()
{
    config.smgr->drawAll();
    config.guienv->drawAll();
}

ChangeScene GameScene::update()
{
    if (config.event->IsKeyDown(KEY_ESCAPE)) {
        return {true, MAIN_MENU};
    }
    updateGame();
    return {false, NONE};
}

const Config &GameScene::getUpdateConfig() const
{
    return (config);
}

//

void GameScene::setMap(std::vector<std::string> setmap)
{
    map = setmap;
}


void GameScene::updateGame()
{
    for (size_t i = 0; i < config.playerList.size(); i++) {
        if (!config.playerList[i]->getIsBot()) {
            playerAction(config.playerList[i]);
        }
    }
}

void GameScene::playerAction(Player *player)
{
    std::stringstream sstr;
    sstr << std::endl;
    core::vector3df nodePosition = player->node->getPosition();
    if (config.event->IsKeyDown(player->getKeys().up)) {
        playerUp(player);
        nodePosition.Y = 60 - (player->getCoord().y * 20);
        player->node->setPosition(nodePosition);
        for (size_t i = 0; i < map.size(); i++) {
            sstr << map[i] << std::endl;
        }
        sstr << std::endl;
        config.log.printInfo(sstr.str());
    }
    if (config.event->IsKeyDown(player->getKeys().down)) {
        playerDown(player);
         nodePosition.Y = 60 - ((float)(player->getCoord().y) * 20);
         player->node->setPosition(nodePosition);
        for (size_t i = 0; i < map.size(); i++) {
            sstr << map[i] << std::endl;
        }
        sstr << std::endl;
        config.log.printInfo(sstr.str());
    }
    if (config.event->IsKeyDown(player->getKeys().left)) {
        playerLeft(player);
        nodePosition.X = -90 + ((float)(player->getCoord().x) * 20);
        player->node->setPosition(nodePosition);
        for (size_t i = 0; i < map.size(); i++) {
            sstr << map[i] << std::endl;
        }
        sstr << std::endl;
        config.log.printInfo(sstr.str());
    }
    if (config.event->IsKeyDown(player->getKeys().right)) {
        playerRight(player);
        nodePosition.X = -90 + ((float)(player->getCoord().x) * 20);
        player->node->setPosition(nodePosition);
        for (size_t i = 0; i < map.size(); i++) {
            sstr << map[i] << std::endl;
        }
        sstr << std::endl;
        config.log.printInfo(sstr.str());
    }
    if (config.event->IsKeyDown(player->getKeys().drop)) {
        playerDrop(player);
    }
}

bool GameScene::isWalkable(coord2d_t coord)
{
    std::string nonWalkable = "XD#P";

    if (nonWalkable.find(map[coord.y][coord.x]) != std::string::npos) {
        return false;
    }
    return true;
}

void GameScene::playerUp(Player *player)
{
    if (isWalkable({player->getCoord().y-1, player->getCoord().x}) && player->MoveClock()) {
        //playerAnimationUp
        map[player->getCoord().y][player->getCoord().x] = ' ';
        player->setCoord({player->getCoord().y-1, player->getCoord().x});
        map[player->getCoord().y][player->getCoord().x] = 'P';
    }
}

void GameScene::playerDown(Player *player)
{
    if (isWalkable({player->getCoord().y+1, player->getCoord().x}) && player->MoveClock()) {
        //playerAnimationDown
        map[player->getCoord().y][player->getCoord().x] = ' ';
        player->setCoord({player->getCoord().y+1, player->getCoord().x});
        map[player->getCoord().y][player->getCoord().x] = 'P';
    }
}

void GameScene::playerLeft(Player *player)
{
    if (isWalkable({player->getCoord().y, player->getCoord().x-1}) && player->MoveClock()) {
        //playerAnimationLeft
        map[player->getCoord().y][player->getCoord().x] = ' ';
        player->setCoord({player->getCoord().y, player->getCoord().x-1});
        map[player->getCoord().y][player->getCoord().x] = 'P';
    }
}

void GameScene::playerRight(Player *player)
{
    if (isWalkable({player->getCoord().y, player->getCoord().x+1}) && player->MoveClock()) {
        //playerAnimationRight
        map[player->getCoord().y][player->getCoord().x] = ' ';
        player->setCoord({player->getCoord().y, player->getCoord().x+1});
        map[player->getCoord().y][player->getCoord().x] = 'P';
    }
}

void GameScene::playerDrop(Player *player)
{
    //drop bomb
}
