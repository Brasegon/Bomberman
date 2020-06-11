/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include "../Menu/AScene.hpp"
#include "../Event/Event.hpp"
#include "Bomb.hpp"

class GameScene : public AScene {
    public:
        GameScene(Config &conf);
        void display() override;
        ChangeScene update() override;
        const Config &getUpdateConfig() const override;
        ~GameScene() override;

        void setMap(std::vector<std::string> map);
        void updateGame();
        void playerAction(Player *player);
        void playerUp(Player *player);
        void playerDown(Player *player);
        void playerLeft(Player *player);
        void playerRight(Player *player);
        void playerDrop(Player *player);
        void explosion(Bomb bomb);
        bool isWalkable(coord2d_t coord);

    private:
        std::vector<std::string> map;
        scene::ISceneNode *node;
        std::vector<Bomb> bombList;
};

#endif /* !GAMESCENE_HPP_ */
