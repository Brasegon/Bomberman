/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MenuSelection
*/

#ifndef MENUSELECTION_HPP_
#define MENUSELECTION_HPP_
#include "../../my.hpp"
#include "../../Engine/Config.hpp"
#include "../../Event/EventMenu.hpp"
#include "../../Logger/Logger.hpp"
#include "../../Player/Player.hpp"
#include "../AScene.hpp"

class MenuSelection : public AScene {
    public:
        enum {
            GUI_CHOOSE_PLAYER_ONE = 2,
            GUI_CHOOSE_PLAYER_TWO,
            GUI_CHOOSE_PLAYER_THREE,
            GUI_CHOOSE_PLAYER_FOUR,
        };
        MenuSelection(Config &conf);
        void display() override;
        ChangeScene update() override;
        void init(Config &conf) override;
        const Config &getUpdateConfig() const override;
        ~MenuSelection() override;
    protected:
    private:
        ChangeScene checkClick(ChangeScene change);
        void initGui();
        bool isActive;
        Logger log;
        ITexture *background;
        std::vector<gui::IGUIEditBox *> boxName;
        std::vector<gui::IGUIButton *> boxButton;
        irr::gui::IGUIButton *launchButton;
};

#endif /* !MENUSELECTION_HPP_ */
