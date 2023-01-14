#ifndef UI_H
#define UI_H

#include "ResourceManager.h"

class UIElement {
public:
    UIElement(texPtr tex, sf::Vector2f pos, sf::Vector2u size);

    void setVisible(bool isVisible);

    sf::Vector2f getPos();
    sf::Vector2u getSize();

    virtual void setPos(sf::Vector2f newPos);
    virtual void setSize(sf::Vector2u newSize);

    virtual void draw(sf::RenderTarget& window) const;

    virtual ~UIElement() = default;

protected:
    UIElement() = default;

    sf::Vector2f pos;
    sf::Vector2u size;

    texPtr texture;
    sf::Sprite sprite;

    bool visible;
};

class UI {
public:
    UI(std::shared_ptr<sf::RenderWindow> win);

    void draw() const;

    void addElement(const std::string& name, UIElement* elem);

private:
    // disallow default construction
    UI() = default;

    std::unordered_map<std::string, UIElement*> elements;
    std::weak_ptr<sf::RenderWindow> window;
};

#endif