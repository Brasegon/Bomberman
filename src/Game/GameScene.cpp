/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameScene
*/

#include "GameScene.hpp"

static SColor pcolor[4] = {
    SColor(0, 0, 255, 0),
    SColor(0, 0, 0, 255),
    SColor(0, 255, 0, 255),
    SColor(0, 255, 255, 0),
};

GameScene::GameScene(Config &conf) : AScene(conf)
{
    srand(time(0));
    config.smgr = config.device->getSceneManager();
    config.guienv = config.device->getGUIEnvironment();
    if (config.newGame) {
        Map mapGen;
        map = mapGen.GenMap(16, 16);
        // map = {
        //     "###############",
        //     "#P DD     DD P#",
        //     "# XXXXX XXXXX #",
        //     "#DX   D D   XD#",
        //     "#DX XXX XXX XD#",
        //     "#   DD   DD   #",
        //     "#XXXX XXX XXXX#",
        //     "# D    X    D #",
        //     "# XXXXXXXXXXX #",
        //     "# D    X    D #",
        //     "#XXXX XXX XXXX#",
        //     "#   DD   DD   #",
        //     "#DX XXX XXX XD#",
        //     "#DX   D D   XD#",
        //     "# XXXXX XXXXX #",
        //     "#P DD     DD P#",
        //     "###############",
        // };
    } else {
        config.playerList = save.getPlayerSave();
        map = save.getMap();
    }
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].length(); j += 1) {
            float x1 = -90 + ((float)(j) * 20);
            float y1 = 60 - ((float)(i) * 20);
            if (map[i][j] == '#' || map[i][j] == 'X') {
                scene::ISceneNode* n = config.smgr->addCubeSceneNode();
                n->setScale(core::vector3df(2, 2, 2));
                n->setMaterialTexture(0, config.driver->getTexture("assets/textures/wallNoDestru.bmp"));
                n->setMaterialFlag(video::EMF_LIGHTING, false);
                n->setPosition(core::vector3df(x1, y1 ,30));
                mapnode.push_back({n, {i, j}, false});
            } else {
                scene::ISceneNode* n = config.smgr->addCubeSceneNode();
                n->setScale(core::vector3df(2, 2, 2));
                n->setMaterialTexture(0, config.driver->getTexture("assets/textures/sand.png"));
                n->setMaterialFlag(video::EMF_LIGHTING, false);
                n->setPosition(core::vector3df(x1, y1 ,50));
                mapnode.push_back({n, {i, j}, false});
            }
            if (map[i][j] == 'D') {
                scene::ISceneNode* n = config.smgr->addCubeSceneNode();
                n->setScale(core::vector3df(2, 2, 2));
                n->setMaterialTexture(0, config.driver->getTexture("assets/textures/rock.png"));
                n->setMaterialFlag(video::EMF_LIGHTING, false);
                n->setPosition(core::vector3df(x1, y1 ,30));
                mapnode.push_back({n, {i, j},true});
            }
        }
    }
    for (size_t i = 0; i < config.playerList.size(); i++) {
        if (config.newGame) {
            config.playerList[i]->initCoord(map);       
        }
        config.log.printInfo("Player"+std::to_string(i)+" position{"+std::to_string(config.playerList[i]->getCoord().y)+" , "+std::to_string(config.playerList[i]->getCoord().x)+"}");
        IMeshSceneNode * mesh = config.smgr->addSphereSceneNode();
        config.smgr->getMeshManipulator()->setVertexColors(mesh->getMesh(), pcolor[i]);
        config.playerList[i]->node = mesh;
        if (config.playerList[i]->node) {
            float y = 60 - ((float)(config.playerList[i]->getCoord().y) * 20);
            float x = -90 + ((float)(config.playerList[i]->getCoord().x) * 20);
            config.log.printInfo("Création du model du joueur 1");
            config.playerList[i]->node->setPosition(core::vector3df(x, y,30));
            config.playerList[i]->node->setMaterialFlag(video::EMF_LIGHTING, true);
        }
    }
    config.setting.music = new sf::Music();
    if (!config.setting.music->openFromFile("assets/musicGame.ogg")) {
        exit(84);
    }
    config.setting.music->setVolume(10);
    config.setting.music->setLoop(true);
    config.setting.music->play();
    // config.smgr->addCameraSceneNodeFPS(0, 3, 1, -1, 0, 0/*, true*/);
    config.smgr->addCameraSceneNode(0, vector3df(20, -100, -250), vector3df(20, -100, 0));
}

GameScene::~GameScene()
{
    save.saveMap(map, config);
    config.setting.music->stop();
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
    // if (config.event->IsKeyDown(KEY_SPACE)) {
    //     config.log.printInfo("Reset Camera");
    //     config.smgr->getActiveCamera()->setRotation(vector3df(20, -100, 0));
    //     config.smgr->getActiveCamera()->setPosition(vector3df(20, -100, -250));
    // }
    size_t count = 0;
    for (size_t i = 0; i < config.playerList.size(); i++) {
        if (!config.playerList[i]->getIsBot()) {
            count++;
        }
    }
    if (config.playerList.size() <= 1 || count == 0) {
        return {true, END};
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
    //player action
    for (size_t i = 0; i < config.playerList.size(); i++) {
        if (!config.playerList[i]->getIsBot()) {
            playerAction(config.playerList[i]);
        } else {
            iaAction(config.playerList[i]);
        }
    }
    //check destructible node
    for (size_t i = 0; i < mapnode.size(); i++) {
        if (mapnode[i].isDestructible) {
            map[mapnode[i].coord.y][mapnode[i].coord.x] = 'D';
        }
    }
    for (size_t i = 0; i < bombList.size(); i++) {
        //check if bomb exploded
        if (bombList[i]->isExploded()) {
            if(bombList[i]->node != NULL) {
                explosion(bombList[i]);
                bombList[i]->node->remove();
                bombList[i]->node = NULL;
            }
        }
        //check if any player got exploded or burnt 
        for (size_t j = 0; j < bombList[i]->firenode.size(); j++) {
            for (size_t k = 0; k < config.playerList.size(); k++) {
                if (bombList[i]->firenode[j].coord == config.playerList[k]->getCoord()) {
                    config.log.printInfo(config.playerList[k]->getPlayerName()+" killed by "+bombList[i]->getPlayer()->getPlayerName());
                    config.playerList[k]->node->remove();
                    map[config.playerList[k]->getCoord().y][config.playerList[k]->getCoord().x] = ' ';
                    delete config.playerList[k];
                    config.playerList.erase(config.playerList.begin()+k);
                }
            }
        }
            //check if fire went out
        if (bombList[i]->isExplosionEnd()) {
            for (size_t j = 0; j < bombList[i]->firenode.size(); j++) {
                bombList[i]->firenode[j].node->remove();
            }
            delete bombList[i];
            bombList.erase(bombList.begin()+i);
        }
    }
    for (size_t i = 0; i < powerupList.size(); i++) {
        //check if powerup despawned
        if (powerupList[i]->isDespawn()) {
            powerupList[i]->node->remove();
            delete powerupList[i];
            powerupList.erase(powerupList.begin()+i);
        }
        //check if player picked up a powerup
        for (size_t j = 0; j < config.playerList.size(); j++) {
            if (config.playerList[j]->getCoord() == powerupList[i]->getCoord()) {
                config.playerList[j]->addBuff(powerupList[i]->getType());
                powerupList[i]->node->remove();
                delete powerupList[i];
                powerupList.erase(powerupList.begin()+i);
            }
        }
    }
}

void GameScene::iaAction(Player *player)
{
    //valeur random
    srand((unsigned) time(0));
    int randomNumber = (rand() % 4) + 1;
    core::vector3df nodePosition = player->node->getPosition();
    if (randomNumber == 1) {
        playerUp(player);
        nodePosition.Y = 60 - ((float)(player->getCoord().y) * 20);
        player->node->setPosition(nodePosition);
    }
    if (randomNumber == 2) {
        playerDown(player);
        nodePosition.Y = 60 - ((float)(player->getCoord().y) * 20);
        player->node->setPosition(nodePosition);
    }
    if (randomNumber == 3) {
        playerLeft(player);
        nodePosition.X = -90 + ((float)(player->getCoord().x) * 20);
        player->node->setPosition(nodePosition);
    }
    if (randomNumber == 4) {
        playerRight(player);
        nodePosition.X = -90 + ((float)(player->getCoord().x) * 20);
        player->node->setPosition(nodePosition);
    }
}

void GameScene::playerAction(Player *player)
{
    core::vector3df nodePosition = player->node->getPosition();
    if (config.event->IsKeyDown(player->getKeys().up)) {
        playerUp(player);
        nodePosition.Y = 60 - ((float)(player->getCoord().y) * 20);
        player->node->setPosition(nodePosition);
    }
    if (config.event->IsKeyDown(player->getKeys().down)) {
        playerDown(player);
        nodePosition.Y = 60 - ((float)(player->getCoord().y) * 20);
        player->node->setPosition(nodePosition);
    }
    if (config.event->IsKeyDown(player->getKeys().left)) {
        playerLeft(player);
        nodePosition.X = -90 + ((float)(player->getCoord().x) * 20);
        player->node->setPosition(nodePosition);
    }
    if (config.event->IsKeyDown(player->getKeys().right)) {
        playerRight(player);
        nodePosition.X = -90 + ((float)(player->getCoord().x) * 20);
        player->node->setPosition(nodePosition);
    }
    if (config.event->IsKeyDown(player->getKeys().drop)) {
        playerDrop(player);
    }
}

bool GameScene::isWalkable(coord2d_t coord, bool wallpass)
{
    std::string nonWalkable = "X#P";

    if (!wallpass) {
        nonWalkable+="D";
    }
    for (size_t i = 0; i < bombList.size(); i++) {
        if (bombList[i]->getCoord() == coord) {
            return false;
        }
    }
    if (nonWalkable.find(map[coord.y][coord.x]) != std::string::npos) {
        return false;
    }
    return true;
}

void GameScene::playerUp(Player *player)
{
    if (isWalkable({player->getCoord().y-1, player->getCoord().x}, player->getBuff().WallPass) && player->MoveClock()) {
        //playerAnimationUp
        map[player->getCoord().y][player->getCoord().x] = ' ';
        player->setCoord({player->getCoord().y-1, player->getCoord().x});
        map[player->getCoord().y][player->getCoord().x] = 'P';
    }
}

void GameScene::playerDown(Player *player)
{
    if (isWalkable({player->getCoord().y+1, player->getCoord().x}, player->getBuff().WallPass) && player->MoveClock()) {
        //playerAnimationDown
        map[player->getCoord().y][player->getCoord().x] = ' ';
        player->setCoord({player->getCoord().y+1, player->getCoord().x});
        map[player->getCoord().y][player->getCoord().x] = 'P';
    }
}

void GameScene::playerLeft(Player *player)
{
    if (isWalkable({player->getCoord().y, player->getCoord().x-1}, player->getBuff().WallPass) && player->MoveClock()) {
        //playerAnimationLeft
        map[player->getCoord().y][player->getCoord().x] = ' ';
        player->setCoord({player->getCoord().y, player->getCoord().x-1});
        map[player->getCoord().y][player->getCoord().x] = 'P';
    }
}

void GameScene::playerRight(Player *player)
{
    if (isWalkable({player->getCoord().y, player->getCoord().x+1}, player->getBuff().WallPass) && player->MoveClock()) {
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
        if (bombList[i]->getCoord() == player->getCoord()) {
            return;
        }
        if (bombList[i]->getPlayer() == player && !bombList[i]->isExploded()) {
            count++;
        }
    }
    for (size_t i = 0; i < mapnode.size(); i++) {
        if (player->getCoord() == mapnode[i].coord && mapnode[i].isDestructible)
            return;
    }
    if (count < 1+player->getBuff().BombUp) {
        bombList.push_back(new Bomb(player));
        bombList[bombList.size()-1]->playSound();
        bombList[bombList.size()-1]->node = config.smgr->addAnimatedMeshSceneNode(config.smgr->getMesh("assets/Bomb.md2"));
        float y = 60 - ((float)(bombList[bombList.size()-1]->getCoord().y) * 20);
        float x = -90 + ((float)(bombList[bombList.size()-1]->getCoord().x) * 20);
        bombList[bombList.size()-1]->node->setPosition(core::vector3df(x, y, 20));
        bombList[bombList.size()-1]->node->setScale(core::vector3df(0.025, 0.025, 0.025));
        bombList[bombList.size()-1]->node->setMaterialFlag(video::EMF_LIGHTING, true);
        bombList[bombList.size()-1]->node->setMaterialTexture(0, config.driver->getTexture("assets/textures/redtexture.jpg"));
    }
}

irr::scene::ISceneNode *GameScene::newFireNode() {
    ISceneNode *node;

    node = config.smgr->addCubeSceneNode();
    node->setScale(vector3df(1.8,1.8,1.8));
    node->setMaterialFlag(video::EMF_LIGHTING, true);
    node->setMaterialTexture(0, config.driver->getTexture("assets/textures/fire.jpg"));
    return node;
}

void GameScene::explosion(Bomb *bomb)
{
    std::string nonDestructible = "X#";
    float y = 0;
    float x = 0;

    coord2d_t bombpos = bomb->getCoord();
    //fire up
    for (size_t i = 0; i < 3+bomb->getPlayer()->getBuff().FireUp && (int)(bombpos.y-i) >= 0; i++) {
        if (nonDestructible.find(map[bombpos.y-i][bombpos.x]) != std::string::npos) {
            break;
        }
        bomb->firenode.push_back({newFireNode(), {bombpos.y-i, bombpos.x}});
        y = 60 - ((float)(bombpos.y-i) * 20);
        x = -90 + ((float)(bombpos.x) * 20);
        bomb->firenode[bomb->firenode.size()-1].node->setPosition(core::vector3df(x, y, 20));
        if (map[bombpos.y-i][bombpos.x] == 'D') {
            map[bombpos.y-i][bombpos.x] = ' ';
            destroyMapNode({bombpos.y-i, bombpos.x});
            spawnPowerUp({bombpos.y-i, bombpos.x});
            break;
        }
        map[bombpos.y-i][bombpos.x] = ' ';
    }
    //fire down
    for (size_t i = 1; i < 3+bomb->getPlayer()->getBuff().FireUp && bombpos.y+i < map.size(); i++) {
        if (nonDestructible.find(map[bombpos.y+i][bombpos.x]) != std::string::npos) {
            break;
        }
        bomb->firenode.push_back({newFireNode(), {bombpos.y+i, bombpos.x}});
        y = 60 - ((float)(bombpos.y+i) * 20);
        x = -90 + ((float)(bombpos.x) * 20);
        bomb->firenode[bomb->firenode.size()-1].node->setPosition(core::vector3df(x, y, 20));
            if (map[bombpos.y+i][bombpos.x] == 'D') {
            map[bombpos.y+i][bombpos.x] = ' ';
            destroyMapNode({bombpos.y+i, bombpos.x});
            spawnPowerUp({bombpos.y+i, bombpos.x});
            break;
        }
        map[bombpos.y+i][bombpos.x] = ' ';
    }
    //fire left
    for (size_t i = 1; i < 3+bomb->getPlayer()->getBuff().FireUp && (int)(bombpos.x-i); i++) {
        if (nonDestructible.find(map[bombpos.y][bombpos.x-i]) != std::string::npos) {
            break;
        }
        bomb->firenode.push_back({newFireNode(), {bombpos.y, bombpos.x-i}});
        y = 60 - ((float)(bombpos.y) * 20);
        x = -90 + ((float)(bombpos.x-i) * 20);
        bomb->firenode[bomb->firenode.size()-1].node->setPosition(core::vector3df(x, y, 20));
        if (map[bombpos.y][bombpos.x-i] == 'D') {
            map[bombpos.y][bombpos.x-i] = ' ';
            destroyMapNode({bombpos.y, bombpos.x-i});
            spawnPowerUp({bombpos.y, bombpos.x-i});
            break;
        }
        map[bombpos.y][bombpos.x-i] = ' ';
    }
    //fire right             
    for (size_t i = 1; i < 3+bomb->getPlayer()->getBuff().FireUp && bombpos.x+i < map[bombpos.y].size(); i++) {
        if (nonDestructible.find(map[bombpos.y][bombpos.x+i]) != std::string::npos) {
            break;
        }
        bomb->firenode.push_back({newFireNode(), {bombpos.y, bombpos.x+i}});
        y = 60 - ((float)(bombpos.y) * 20);
        x = -90 + ((float)(bombpos.x+i) * 20);
        bomb->firenode[bomb->firenode.size()-1].node->setPosition(core::vector3df(x, y, 20));
        if (map[bombpos.y][bombpos.x+i] == 'D') {
            map[bombpos.y][bombpos.x+i] = ' ';
            spawnPowerUp({bombpos.y, bombpos.x+i});
            destroyMapNode({bombpos.y, bombpos.x+i});
            break;
        }
        map[bombpos.y][bombpos.x+i] = ' ';
    }
}

void GameScene::destroyMapNode(coord2d_t coord)
{
    for (size_t i = 0; i < mapnode.size(); i++) {
        if (mapnode[i].coord == coord && mapnode[i].isDestructible) {
            mapnode[i].node->remove();
            mapnode.erase(mapnode.begin()+i);
        }
    }
}

void GameScene::spawnPowerUp(coord2d_t coord)
{
    PowerUp *powup = new PowerUp();
    int r = rand()%4;
    
    if (rand()%2 == 0) {
        delete powup;
        return;
    }
    powup->setCoord(coord);
    powup->node = config.smgr->addCubeSceneNode();
    float y = 60 - ((float)(coord.y) * 20);
    float x = -90 + ((float)(coord.x) * 20);
    powup->node->setPosition(core::vector3df(x, y, 30));
    powup->node->setScale(core::vector3df(1.5, 1.5, 1.5));
    powup->node->setMaterialFlag(video::EMF_LIGHTING, true);
    switch (r)
    {
    case 0:
        powup->setType(BOMBUP);
        powup->node->setMaterialTexture(0, config.driver->getTexture("assets/textures/Bomb_Up.png"));
        break;
    case 1:
        powup->setType(FIREUP);
        powup->node->setMaterialTexture(0, config.driver->getTexture("assets/textures/Fire_Up.png"));
        break;
    case 2:
        powup->setType(SPEEDUP);
        powup->node->setMaterialTexture(0, config.driver->getTexture("assets/textures/Speed_Up.png"));
        break;
    case 3:
        powup->setType(WALLPASS);
        powup->node->setMaterialTexture(0, config.driver->getTexture("assets/textures/Wall_Pass.png"));
        break;
    default:
        break;
    }
    powerupList.push_back(powup);
}
