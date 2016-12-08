#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
using namespace std;


class czmija : public sf::Transformable, public sf::Drawable, public sf::VertexArray{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(head, states);
		target.draw(body, states);
	}
public:
	float x;
	float y;
	float pi = 3.14159265359;
	int pozX, pozY;
	float moveX;
	float moveY;
	int start_direction;
	int counter = 0;
	sf::CircleShape head;
	sf::VertexArray body;
	sf::Vertex a;
	sf::Vertex b;
	sf::Vertex c;
	sf::Vertex d;
	int speed = 3;
	float angle;
	float radian_angle;
	float speedX;
	float speedY;
	bool addA = true;
	bool addB = false;
	bool addC = false;
	sf::Vertex collisionA;
	sf::Vertex collisionB;
	sf::Vertex collisionC;
	int brojacSudara = 0;
	bool bodyChecker = true;
	bool alive = true;
	

	
	

	// define the position of the triangle's points

	czmija() {
	}

	void start() {
		head.setRadius(6);
		head.setFillColor(sf::Color::Yellow);
		body.setPrimitiveType(sf::Quads);
	}

	void start_position() {
		srand(time(NULL));
		x = rand() % 1366;
		y = rand() % 768;
		head.setPosition(sf::Vector2f(x, y));
		moveX = x;
		moveY = y;
	}

	void starting_direction() {
		srand(time(NULL));
		start_direction = rand() % 2;
		cout << start_direction << endl;
	}

	void move_onStart() {
		if (start_direction == 0) {
			moveX = moveX - 1 * 0.3;
			moveY = moveY - 1 * 0.3;
		}
		else if (start_direction == 1) {
			moveX = moveX - 1 * 0.3 * (-1);
			moveY = moveY - 1 * 0.3 * (-1);
		}
		else if (start_direction == 2) {
			moveX = moveX - 1 * 0.3 * (-1);
			moveY = moveY - 1 * 0.3;
		}
		else {
			moveX = moveX - 1 * 0.3;
			moveY = moveY - 1 * 0.3 * (-1);
		}

		head.setPosition(sf::Vector2f(moveX, moveY));
	}

	void move() {
			moveX = moveX += speedX;
			moveY = moveY += speedY;
			head.setPosition(sf::Vector2f(moveX, moveY));
	}
	void make_body() {
			x = moveX;
			y = moveY;

			if (bodyChecker == false)
			{
				counter++;
				if (counter == 13)
					bodyChecker = true;
			}


			if (bodyChecker == true)
			{
				counter = 0; 
				a.texCoords = sf::Vector2f(x-4, y-4);
				b.texCoords = sf::Vector2f(x + 4 , y + 4);
				c.texCoords = sf::Vector2f(x + 4, y - 4);
				d.texCoords = sf::Vector2f(x - 4, y + 4);
				a.position = sf::Vector2f(x - 4, y - 4);
				b.position = sf::Vector2f(x - 4, y - 4);
				c.position = sf::Vector2f(x + 4, y - 4);
				d.position = sf::Vector2f(x - 4, y + 4);
				body.append(a);
				body.append(b);
				body.append(c);
				body.append(d);
				bodyChecker = checkForMakingBody();
			}

	}
	void rotate_left() {
		head.rotate(-4);
	}

	void rotate_right() {
		head.rotate(4);
	}

	void radians() {
		radian_angle = head.getRotation() * (pi / 180);
		//cout << radian_angle << endl;
	}

	void calculate_speed() {
		speedX = cos(radian_angle) * speed;
		speedY = sin(radian_angle) * speed;
		//cout << "x: "<<speedX << endl;
		//cout << "y: "<<speedY << endl;
	}

	int rememberX() {
		return x;
	}
	int rememberY() {
		return y;
	}

	sf::Vertex GetCollisionA(){
		collisionA.texCoords = a.texCoords;
		collisionA.position = a.position;
		return collisionA;
	}

	sf::Vertex GetCollisionB() {
		collisionB.texCoords = b.texCoords;
		collisionB.position = b.position;
		return collisionB;
	}

	sf::Vertex GetCollisionC() {
		collisionC.texCoords = c.texCoords;
		collisionC.position = c.position;
		return collisionC;
	}

	bool checkForMakingBody() {
		int boolChecker = 0;
		boolChecker = rand() % 100;
		if (boolChecker >= 0 & boolChecker <= 1)
			return false;
		else
			return true;
	}

	bool isAlive() {
		return alive;
	}


};

