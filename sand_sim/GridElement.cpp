#include "GridElement.h"

GridElement::GridElement() {

}

GridElement::~GridElement() {

}

void GridElement::initGridElement(int type, sf::Vector2u gridPos) {
	
	this->type = type;
	this->gridPosition = gridPos;

}
