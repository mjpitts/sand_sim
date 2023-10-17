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
void GridElement::initGridElement(sf::Vector2f screenPos, float tileSize, sf::Color fillColor, sf::Color outColor) {
    this->screenPosition = screenPos;
    this->tileSize = tileSize;
    this->fillColor = fillColor;
    this->outlineColor = outColor;

    shape.setPosition(screenPos.x, screenPos.y);
    shape.setSize(sf::Vector2f(tileSize, tileSize));
    shape.setFillColor(fillColor);
    shape.setOutlineColor(outColor);
    shape.setOutlineThickness(this->OUTLINE_W);
}
