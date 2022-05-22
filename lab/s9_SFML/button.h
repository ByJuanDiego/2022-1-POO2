//
// Created by Juan Diego Castro Padilla on 19/05/22.
//

#ifndef S9_SFML_BUTTON_H
#define S9_SFML_BUTTON_H

#include "component.h"
#include "render.h"
#include <SFML/Graphics.hpp>

class button_t: public component_t {
public:

    // button_t(float x, float y, float w, float h): component_t(x, y, w, h) {}
    using component_t::component_t;

    void draw() override
    {
        auto& canvas = render<sf::RenderWindow>::get_instance()->get();
        sf::RectangleShape shape({width, height});
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Red);

        // Crear el texto
        sf::Font font;
        sf::Text txt;
        if (font.loadFromFile("./Oxanium-Regular.ttf"))
        {
            txt.setFont(font);
            txt.setFillColor(sf::Color::Blue);
            txt.setCharacterSize(20);
            txt.setString(text);
            txt.setPosition(x , y);
            // Para centrar el texto en el recuadro
            const auto bounds(txt.getLocalBounds());
            const auto box(shape.getSize());
            txt.setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);
        }

        canvas->draw(shape);
        canvas->draw(txt);
    }

};


#endif //S9_SFML_BUTTON_H
