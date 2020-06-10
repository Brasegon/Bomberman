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
    setMap({""});
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
    if (config.event->IsKeyDown(player->getKeys().up)) {
        playerUp(player);
    }
    if (config.event->IsKeyDown(player->getKeys().down)) {
        playerUp(player);
    }
    if (config.event->IsKeyDown(player->getKeys().left)) {
        playerUp(player);
    }
    if (config.event->IsKeyDown(player->getKeys().right)) {
        playerUp(player);
    }
    if (config.event->IsKeyDown(player->getKeys().right)) {
        playerDrop(player);
    }
}

bool GameScene::isWalkable(coord2d_t coord)
{
    std::string nonWalkable = "XD#";

    if (nonWalkable.find(map[coord.y][coord.x]) != std::string::npos) {
        return false;
    }
    return true;
}

void GameScene::playerUp(Player *player)
{
    if (isWalkable({player->getCoord().y-1, player->getCoord().x})) {
        //playerAnimationUp
        map[player->getCoord().y][player->getCoord().x] = ' ';
        map[player->getCoord().y-1][player->getCoord().x] = 'P';
    }
}

void GameScene::playerDown(Player *player)
{
    if (isWalkable({player->getCoord().y+1, player->getCoord().x})) {
        //playerAnimationDown
        map[player->getCoord().y][player->getCoord().x] = ' ';
        map[player->getCoord().y+1][player->getCoord().x] = 'P';
    }
}

void GameScene::playerLeft(Player *player)
{
    if (isWalkable({player->getCoord().y, player->getCoord().x-1})) {
        //playerAnimationLeft
        map[player->getCoord().y][player->getCoord().x] = ' ';
        map[player->getCoord().y][player->getCoord().x-1] = 'P';
    }
}

void GameScene::playerRight(Player *player)
{
    if (isWalkable({player->getCoord().y, player->getCoord().x+1})) {
        //playerAnimationRight
        map[player->getCoord().y][player->getCoord().x] = ' ';
        map[player->getCoord().y][player->getCoord().x+1] = 'P';
    }
}

void GameScene::playerDrop(Player *player)
{
    //drop bomb
}
