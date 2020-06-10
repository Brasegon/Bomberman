/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AScene
*/
#include "IScene.hpp"
#include "../my.hpp"
#include "../Engine/Config.hpp"
#include "../Event/Event.hpp"
#include "../Logger/Logger.hpp"
#ifndef ASCENE_HPP_
#define ASCENE_HPP_

class AScene : public IScene {
    public:
        AScene(Config &conf) : config(conf) {
            config.event->clear();
        }
        IGUIButton *addButton(irr::s32 x, irr::s32 y, irr::s32 lo, irr::s32 la, std::wstring title, irr::s32 guiId)
        {
            IGUIButton *button = config.guienv->addButton(rect<s32>(x, y, x + lo, y + la), 0, guiId,
                    title.c_str(), NULL);
            
            return button;
        }
        IGUIEditBox *addEditBox(irr::s32 x, irr::s32 y, irr::s32 lo, irr::s32 la, std::wstring title)
        {
            IGUIEditBox *button = config.guienv->addEditBox(title.c_str(), irr::core::rect<irr::s32>(x, y, x + lo, y + la));
            return button;
        }
        ~AScene() override = default;

    protected:
        Config config;
    private:
};

#endif /* !ASCENE_HPP_ */
