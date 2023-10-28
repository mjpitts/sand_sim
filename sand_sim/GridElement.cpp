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

elementTypes GridElement::getType() const
{
    return this->type;
}

bool GridElement::getSeen() const {

    return this->seen;

}

// Setter
void GridElement::initGridElement(sf::Vector2f screenPos, float tileSize, elementTypes type) {
    this->screenPosition = screenPos;
    this->tileSize = tileSize;
    this->type = type;
    this->seen = false;

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

    case elementTypes::SAND:
        shape.setFillColor(sf::Color(205, 174, 102));
        shape.setOutlineColor(sf::Color(171, 139, 65, 50));
        this->fillColor = sf::Color(205, 174, 102);
        this->outlineColor = sf::Color(171, 139, 65, 50);
        break;

    case elementTypes::WOOD:
        shape.setFillColor(sf::Color(69, 45, 7));
        shape.setOutlineColor(sf::Color(84, 55, 8, 50));
        this->fillColor = sf::Color(205, 174, 102);
        this->outlineColor = sf::Color(171, 139, 65, 50);
        break;

    default:
        std::cout << "ERROR: typing error in GridElement.cpp, default case reached. \n";
        break;
    }
}

void GridElement::setType(elementTypes type) {
    this->type = type;
}

void GridElement::setSeen(bool status) {

    this->seen = status;

}

// Update element when it is transformed
void GridElement::updateElement() {

    switch (this->type)
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

    case elementTypes::SAND:
        shape.setFillColor(sf::Color(205, 174, 102));
        shape.setOutlineColor(sf::Color(171, 139, 65, 50));
        this->fillColor = sf::Color(205, 174, 102);
        this->outlineColor = sf::Color(171, 139, 65, 50);
        break;

    case elementTypes::WOOD:
        shape.setFillColor(sf::Color(69, 45, 7));
        shape.setOutlineColor(sf::Color(84, 55, 8, 50));
        this->fillColor = sf::Color(205, 174, 102);
        this->outlineColor = sf::Color(171, 139, 65, 50);
        break;

    default:
        std::cout << "ERROR: default case reached in elementUpdate. \n";
        break;
    }

}

