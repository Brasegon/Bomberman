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
        "#             #",
        "#             #",
        "#             #",
        "#             #",
        "#             #",
        "#             #",
        "#P           P#",
        "###############",
    };
    std::vector<irr::scene::ISceneNode *> nodeList;
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].length(); j += 1) {
            float x1 = -90 + ((float)(j) * 20);
            float y1 = 60 - ((float)(i) * 20);
            if (map[i][j] != 'P' && map[i][j] != ' ') {
                scene::ISceneNode* n = config.smgr->addCubeSceneNode();
                n->setScale(core::vector3df(2, 2, 2));
                n->setMaterialTexture(0, config.driver->getTexture("assets/textures/wallNoDestru.bmp"));
                n->setMaterialFlag(video::EMF_LIGHTING, false);
                n->setPosition(core::vector3df(x1, y1 ,30));
                nodeList.push_back(n);
            } else {
                scene::ISceneNode* n = config.smgr->addCubeSceneNode();
                n->setScale(core::vector3df(2, 2, 2));
                n->setMaterialTexture(0, config.driver->getTexture("assets/textures/sand.png"));
                n->setMaterialFlag(video::EMF_LIGHTING, false);
                n->setPosition(core::vector3df(x1, y1 ,50));
            }
        }
    }
    for (size_t i = 0; i < config.playerList.size(); i++) {
        config.playerList[i]->initCoord(map);
        config.log.printInfo("Player"+std::to_string(i)+" position{"+std::to_string(config.playerList[i]->getCoord().y)+" , "+std::to_string(config.playerList[i]->getCoord().x)+"}");
        config.playerList[i]->node = config.smgr->addSphereSceneNode();
        if (config.playerList[i]->node) {
            float y = 60 - ((float)(config.playerList[i]->getCoord().y) * 20);
            float x = -90 + ((float)(config.playerList[i]->getCoord().x) * 20);
            config.log.printInfo("Création du model du joueur 1");
            config.playerList[i]->node->setPosition(core::vector3df(x, y,30));
            config.playerList[i]->node->setMaterialFlag(video::EMF_LIGHTING, true);
        }
    }

    // config.smgr->addCameraSceneNodeFPS(0, 3, 1, -1, 0, 0/*, true*/);
    config.smgr->addCameraSceneNode(0, vector3df(0, 0, -300), vector3df(0, 0, 0));
}

GameScene::~GameScene()
{
    config.smgr->clear();
    config.guienv->clear();
    config.driver->clearZBuffer();
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
    if (config.event->IsKeyDown(KEY_SPACE)) {
        config.log.printInfo("Reset Camera");
        config.smgr->getActiveCamera()->setRotation(vector3df(0, 0, 0));
        config.smgr->getActiveCamera()->setPosition(vector3df(0, 45, -300));
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
    for (size_t i = 0; i < bombList.size(); i++) {
        if (bombList[i]->isExploded()) {
            explosion(bombList[i]);
            bombList.erase(bombList.begin()+i);
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
        nodePosition.Y = 60 - ((float)(player->getCoord().y) * 20);
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
    for (size_t i = 0; i < bombList.size(); i++) {
        if (bombList[i]->getCoord() == coord) {
            return false;
        }
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
    size_t count = 0;
    for (size_t i = 0; i < bombList.size(); i++) {
        if (bombList[i]->getPlayer() == player) {
            count++;
        }
    }
    if (count < 1+player->getBuff().BombUp) {
        bombList.push_back(new Bomb(player));
        bombList[bombList.size()-1]->node = config.smgr->addAnimatedMeshSceneNode(config.smgr->getMesh("assets/Bomb.md2"));
        float y = 60 - ((float)(bombList[bombList.size()-1]->getCoord().y) * 20);
        float x = -90 + ((float)(bombList[bombList.size()-1]->getCoord().x) * 20);
        bombList[bombList.size()-1]->node->setPosition(core::vector3df(x, y, 20));
        bombList[bombList.size()-1]->node->setScale(core::vector3df(0.05, 0.05, 0.05));
        bombList[bombList.size()-1]->node->setMaterialFlag(video::EMF_LIGHTING, true);
        bombList[bombList.size()-1]->node->setMaterialTexture(0, config.driver->getTexture("assets/textures/redtexture.jpg"));
    }
}

void GameScene::explosion(Bomb *bomb)
{
    std::string nonDestructible = "X#";

    coord2d_t bombpos = bomb->getCoord();
    //fire up
    for (size_t i = 0; i < 3+bomb->getPlayer()->getBuff().FireUp && (int)(bombpos.y-i) >= 0; i++) {
        for (size_t j = 0; j < config.playerList.size(); j++) {
            if(config.playerList[j]->getCoord().x == bombpos.x && config.playerList[j]->getCoord().y == bombpos.y-i) {
                //player die
                config.log.printInfo(config.playerList[j]->getPlayerName()+" killed by "+bomb->getPlayer()->getPlayerName());
                config.playerList[j]->node->remove();
                config.playerList.erase(config.playerList.begin()+j);
            }
        }
        if (nonDestructible.find(map[bombpos.y-i][bombpos.x]) != std::string::npos) {
            break;
        }
        else {
            map[bombpos.y-i][bombpos.x] = ' ';
        }
    }
    //fire down
    for (size_t i = 1; i < 3+bomb->getPlayer()->getBuff().FireUp && bombpos.y+i < map.size(); i++) {
        for (size_t j = 0; j < config.playerList.size(); j++) {
            if(config.playerList[j]->getCoord().x == bombpos.x && config.playerList[j]->getCoord().y == bombpos.y+i) {
                //player die
                config.log.printInfo(config.playerList[j]->getPlayerName()+" killed by "+bomb->getPlayer()->getPlayerName());
                config.playerList[j]->node->remove();
                config.playerList.erase(config.playerList.begin()+j);
            }
        }
        if (nonDestructible.find(map[bombpos.y+i][bombpos.x]) != std::string::npos) {
            break;
        }
        else {
            map[bombpos.y+i][bombpos.x] = ' ';
        }
    }
    //fire left
    for (size_t i = 1; i < 3+bomb->getPlayer()->getBuff().FireUp && (int)(bombpos.x-i); i++) {
        for (size_t j = 0; j < config.playerList.size(); j++) {
            if(config.playerList[j]->getCoord().x == bombpos.x-i && config.playerList[j]->getCoord().y == bombpos.y) {
                //player die
                config.log.printInfo(config.playerList[j]->getPlayerName()+" killed by "+bomb->getPlayer()->getPlayerName());
                config.playerList[j]->node->remove();
                config.playerList.erase(config.playerList.begin()+j);
            }
        }
        if (nonDestructible.find(map[bombpos.y][bombpos.x-i]) != std::string::npos) {
            break;
        }
        else {
            map[bombpos.y][bombpos.x-i] = ' ';
        }
    }
    //fire right             
    for (size_t i = 1; i < 3+bomb->getPlayer()->getBuff().FireUp && bombpos.x+i < map[bombpos.y].size(); i++) {
        for (size_t j = 0; j < config.playerList.size(); j++) {
            if(config.playerList[j]->getCoord().x == bombpos.x+i && config.playerList[j]->getCoord().y == bombpos.y) {
                //player die
                config.log.printInfo(config.playerList[j]->getPlayerName()+" killed by "+bomb->getPlayer()->getPlayerName());
                config.playerList[j]->node->remove();
                config.playerList.erase(config.playerList.begin()+j);
            }
        }
        if (nonDestructible.find(map[bombpos.y][bombpos.x+i]) != std::string::npos) {
            break;
        }
        else {
            map[bombpos.y][bombpos.x+i] = ' ';
        }
    }
    if(bomb->node != NULL)
        bomb->node->remove();
}
