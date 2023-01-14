#include "../include/UI.h"

UIElement::UIElement(texPtr tex, sf::Vector2f pos, sf::Vector2u size)
    : pos(pos), size(size) {
    texture = tex;
    sprite.setTexture(*texture);
    sprite.setPosition(pos);
    sprite.setScale(getScaleFactor(sprite, size));

    visible = false;
}

void UIElement::setVisible(const bool isVisible) { visible = isVisible; }

sf::Vector2f UIElement::getPos() { return pos; }

sf::Vector2u UIElement::getSize() { return size; }

void UIElement::setPos(sf::Vector2f newPos) {
    pos = newPos;
    sprite.setPosition(pos);
}

void UIElement::setSize(sf::Vector2u newSize) {
    size = newSize;
    sprite.setScale(getScaleFactor(sprite, size));
}

void UIElement::draw(sf::RenderTarget& window) const {
    if (visible) {
        window.draw(sprite);
    }
}

UI::UI(std::shared_ptr<sf::RenderWindow> win) : window(win) {}

void UI::draw() const {
    auto win = window.lock();
    for (auto elem : elements) {
        elem.second->draw(*win);
    }
}

void UI::addElement(const std::string& name, UIElement* elem) {
    elements.emplace(name, elem);
}