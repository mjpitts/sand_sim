#include <iostream>
#include "GridElement.h"


// Getters 
sf::Vector2f GridElement::getScreenPosition() const{
    return this->screenPosition;
}

float GridElement::getTileSize() const {
    return this->tileSize;
}

float GridElement::getOutlineWidth() const {
    return this->OUTLINE_W;
}

sf::Color GridElement::getFillColor() const {
    return this->fillColor;
}

sf::Color GridElement::getOutlineColor() const {
    return this->outlineColor;
}

sf::RectangleShape GridElement::getShape() const {
    return this->shape;
}

// Setter
void GridElement::initGridElement(sf::Vector2f screenPos, float tileSize, elementTypes type) {
    this->screenPosition = screenPos;
    this->tileSize = tileSize;
    this->type = type;

    // This Block sets the visual attributes of the element
    shape.setPosition(screenPos.x, screenPos.y);
    shape.setSize(sf::Vector2f(tileSize, tileSize));
    shape.setOutlineThickness(this->OUTLINE_W);

    switch (type)
    {
    case elementTypes::EMPTY:
        shape.setFillColor(sf::Color::Black);
        shape.setOutlineColor(sf::Color(0, 255, 0, 50));
        this->fillColor = sf::Color::Black;
        this->outlineColor = sf::Color(0, 255, 0, 50);
        break;

    case elementTypes::WATER:
        shape.setFillColor(sf::Color::Blue);
        shape.setOutlineColor(sf::Color(0, 128, 255, 50));
        this->fillColor = sf::Color::Blue;
        this->outlineColor = sf::Color(0, 128, 255, 50);
        break;

    default:
        std::cout << "ERROR: typing error in GridElement.cpp, default case reached. \n";
        break;
    }
}
