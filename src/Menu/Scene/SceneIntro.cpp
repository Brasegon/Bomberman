/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SceneIntro
*/

#include "SceneIntro.hpp"

SceneIntro::SceneIntro(Config &conf) : AScene(conf)
{
    config.smgr = config.device->getSceneManager();
    config.guienv = config.device->getGUIEnvironment();
    config.smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
    start = std::chrono::system_clock::now();
}

void SceneIntro::display()
{
    config.smgr->drawAll();
    config.guienv->drawAll();
}
const Config &SceneIntro::getUpdateConfig() const
{
    return (config);
}
ChangeScene SceneIntro::update()
{
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    if (elapsed.count() > 2) {
        return {true, MAIN_MENU};
    }
    return {false, NONE};
}

SceneIntro::~SceneIntro()
{
}
