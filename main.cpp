#include <SFML/Graphics.hpp>

#include "./include/ResourceManager.h"

int main() {
    ResourceManager man;
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(200, 200),
                                                     "SFML works!");

    man.tex_FromFile("assets/images/smiley.png", "jeff");

    sf::Sprite sprite(*man.getTexture("jeff"));

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear(sf::Color::Red);
        window->draw(sprite);
        window->display();
    }

    return 0;
}