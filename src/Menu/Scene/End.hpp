/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** End
*/

#ifndef END_HPP_
#define END_HPP_
#include "../../my.hpp"
#include "../../Engine/Config.hpp"
#include "../../Event/Event.hpp"
#include "../../Logger/Logger.hpp"
#include "../AScene.hpp"

class End : public AScene {
    public:
        End(Config &conf);
        ~End();
        void display() override;
        const Config &getUpdateConfig() const override;
        ChangeScene update() override;
    protected:
    private:
        ChangeScene checkClick(ChangeScene change);
        Logger log;
        ITexture *background;
};

#endif /* !END_HPP_ */
