#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "./include/ResourceManager.h"
#include "./include/UI.h"

int main() {
    ResourceManager man;
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(200, 200),
                                                     "SFML works!");
    window->setFramerateLimit(60);
    float lastTime = 0;
    sf::Clock clock;

    man.tex_FromFile("assets/images/smiley.png", "jeff");

    UIElement elem(man.getTexture("jeff"), sf::Vector2f(0, 0), sf::Vector2u(100, 30));
    elem.setVisible(true);

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        elem.setPos(elem.getPos()+sf::Vector2f(1, 0));

        window->clear(sf::Color::Red);
        elem.draw(*window);
        window->display();

        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / lastTime;
        lastTime = currentTime;

        // window->setTitle(std::to_string(fps));
        std::cout << fps << std::endl;
    }

    return 0;
}