#ifndef GRIDELEMENT_H
#define GRIDELEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class GridElement
{
private:
	
	// Type of element
	int type;
	sf::Vector2u gridPosition;

public:

	// Constructor / Destructor
	GridElement();
	virtual ~GridElement();

	// Init function 
	void initGridElement(int type, sf::Vector2u gridPos);

};

#endif
