#ifndef UI_H
#define UI_H

#include "ResourceManager.h"

class UIElement {
public:
    UIElement(texPtr tex);
    
    void setVisible(bool isVisible);

    sf::Vector2f getPos();
    sf::Vector2u getSize();

    virtual sf::Vector2f setPos(const sf::Vector2f newPos);
    virtual sf::Vector2u setSize(const sf::Vector2u newSize);

    virtual void draw(sf::RenderTarget& window);

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
    UI(ResourceManager* manager);

private:
    // disallow default construction
    UI();

    ResourceManager* man;
    std::unordered_map<std::string, UIElement*> elements;
};

#endif