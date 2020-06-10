/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SceneIntro
*/

#ifndef SCENEINTRO_HPP_
#define SCENEINTRO_HPP_
#include "../../my.hpp"
#include "../../Engine/Config.hpp"
#include "../../Event/Event.hpp"
#include "../../Logger/Logger.hpp"
#include "../../Player/Player.hpp"
#include "../AScene.hpp"

class SceneIntro : public AScene {
    public:
        SceneIntro(Config &conf);
        void display() override;
        ChangeScene update() override;
        const Config &getUpdateConfig() const override;
        ~SceneIntro() override;

    protected:
    private:
        std::chrono::system_clock::time_point start;
};

#endif /* !SCENEINTRO_HPP_ */
