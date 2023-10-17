#ifndef GRIDELEMENT_H
#define GRIDELEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum class elementTypes{
	EMPTY, WATER
};

class GridElement
{
private:

	// Position of element on screen
	sf::Vector2f screenPosition;
	// Number of pixel for heigh and width
	float tileSize;
	// Outline width, const of all elements
	const float OUTLINE_W = 1.f;
	// Fill color of grid element 
	sf::Color fillColor;
	// outline color of grid element 
	sf::Color outlineColor;
	// Shape of gridElement
	sf::RectangleShape shape;
	// Type of grid element
	elementTypes type;
	
public:
	// Getters
	sf::Vector2f getScreenPosition() const;

	float getTileSize() const;

	float getOutlineWidth() const;

	sf::Color getFillColor() const;

	sf::Color getOutlineColor() const;

	sf::RectangleShape getShape() const;

	// Setters 
	void initGridElement(sf::Vector2f screenPosition, float tileSize, elementTypes type);

};

#endif

