#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
using namespace std;

class collisionView : public sf::Transformable, public sf::Drawable, public sf::VertexArray {
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(colisionShape, states);
	}
public:
	sf::VertexArray colisionShape;
	sf::Vertex a;
	sf::Vertex b;
	sf::Vertex c;
	sf::Vertex d;
	std::vector<sf::VertexArray> vertexArrayVector;
	int xCord = 0;
	int yCord = 0;
	int stackX[10];
	int stackY[10];
	int x;
	int y;
	bool insertX;
	bool insertY;
	bool insertedX;
	bool insertedY;

	collisionView() {
		colisionShape.setPrimitiveType(sf::Triangles);
	}

	//umjesto x-a i y-a ubaciti Vertexe iz prave zmije, ali od prije par frameova(?)

	void createCollisionBody() {
		if (xCord != 0 && yCord != 0) {
			a.texCoords = sf::Vector2f(xCord - 2, yCord + 2);
			b.texCoords = sf::Vector2f(xCord - 2 , yCord - 2);
			c.texCoords = sf::Vector2f(xCord + 2, yCord - 2);
			//d.texCoords = sf::Vector2f(x - 2, y + 2);
			a.position = sf::Vector2f(xCord - 2, yCord + 2);
			b.position = sf::Vector2f(xCord - 2, yCord - 2);
			c.position = sf::Vector2f(xCord + 2, yCord - 2);
			sf::VertexArray *v1 = new sf::VertexArray;
			v1->append(a);
			v1->append(b);
			v1->append(c);
			vertexArrayVector.push_back(*v1);

			
		}
	}
	
	bool checkCollision(sf::CircleShape head, int brojac) {
		for (int i = 0; i < vertexArrayVector.size(); i++) {
			if (head.getGlobalBounds().intersects(vertexArrayVector[i].getBounds())) {
				return true;
			}
		}
		return false;
	}

	void RemmberPosition(sf::Vertex a1, sf::Vertex b1, sf::Vertex c1) {
		a = a1;
		b = b1;
		c = c1;
	}

	void MenageStackX(int x) {
		insertedX = false;
		for (int i = 0; i < 10; i++) {
			if (stackX[i] == 0 && insertedX == false) {
				stackX[i] = x;
				if (i <= 8) insertY = true;
				else insertY = false;
				insertedX = true;
			}
			else
				insertX = false;
		}

		if (insertX == false) {
			xCord = stackX[0];
			for (int i = 0; i < 10; i++) {
				if (i != 0) {
					stackX[i - 1] = stackX[i];
				}
				if (i == 9) {
					stackX[i] = x;
				}
			}
		}
	}

	void MenageStackY(int y) {
		insertedY = false;
		for (int i = 0; i < 10; i++) {
			if (stackY[i] == 0 && insertedY == false) {
				stackY[i] = y;
				if(i<= 8) insertY = true;
				else insertY = false;
				insertedY = true;
			}
			else
				insertY = false;
		}
		if (insertY == false){
			yCord = stackY[0];
			for (int i = 0; i < 10; i++) {
				if (i != 0) {
					stackY[i - 1] = stackY[i];
				}
				if (i == 9) {
					stackY[i] = y;
				}
			}
				
		}
	}
};