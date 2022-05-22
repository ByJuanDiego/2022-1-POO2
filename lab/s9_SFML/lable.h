//
// Created by Juan Diego Castro Padilla on 19/05/22.
//

#ifndef S9_SFML_LABLE_H
#define S9_SFML_LABLE_H

#include "component.h"
#include <SFML/Graphics.hpp>
#include "render.h"
#include <iostream>

class label_t: public component_t {
public:

    using component_t::component_t;

    void draw () override
    {
        sf::Font font;
        sf::Text txt;
        if (font.loadFromFile("./Oxanium-Regular.ttf"))
        {
            txt.setFont(font);
            txt.setFillColor(sf::Color::Yellow);
            txt.setCharacterSize(20);
            txt.setString(text);
            txt.setPosition(x , y);
        }
        auto& canvas = render<sf::RenderWindow>::get_instance()->get();
        canvas->draw(txt);
    }

};



#endif //S9_SFML_LABLE_H
