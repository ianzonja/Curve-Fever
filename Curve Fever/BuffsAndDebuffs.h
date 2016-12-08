#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <list>
using namespace std;

class BuffAndDebuff {
public:
	sf::CircleShape itemShape;
	int x;
	int y;
	int randomType;
	int randomIndex;
	list<string> greenItems = { "Brzo", "Sporo", "Sirko", "Nestajanje" };
	list<string> redItems = { "Brzo", "Sporo", "PromjenaSmjera" };
	list<string> blueItems = { "SveIspocetka", "ProlazenjeKroZid" };
	
	BuffAndDebuff() {
	}

	void CreateItem() {
		itemShape.setRadius(25);
		x = rand() % 1366;
		y = rand() % 768;
		itemShape.setPosition(x, y);
		
	}
};