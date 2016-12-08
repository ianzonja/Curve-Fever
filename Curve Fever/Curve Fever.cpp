// Curve Fever.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Zmija.h"
#include "CollisionView.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <ctime>

int main()
{
	clock_t start;
	bool key_pressed = false;
	int x;
	int y;
	bool startCollisionBody = false;
	int brojac = 0;
	double duration;

	start = std::clock();

	sf::ContextSettings settings;
	settings.antialiasingLevel = 32;
	sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML shapes", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	czmija zmija;
	collisionView collisionShape;
	


	zmija.start();
	zmija.starting_direction();
	zmija.start_position();
	zmija.move_onStart();


	while (window.isOpen()) 
	{
		/* Your algorithm here */

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		if (zmija.isAlive()) {
			brojac++;
			zmija.make_body();
			zmija.radians();
			zmija.calculate_speed();
			zmija.move();

			if (zmija.bodyChecker != false) {
				collisionShape.MenageStackX(zmija.x);
				collisionShape.MenageStackY(zmija.y);
			}
			collisionShape.createCollisionBody();
			cout << duration << endl;
			if (collisionShape.checkCollision(zmija.head, brojac) == true && duration > 5.00)
			{
				zmija.alive = false;
			}
			startCollisionBody = true;


			if (brojac == 100)
				brojac = 0;
		}
		


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			zmija.rotate_left();
			key_pressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			zmija.rotate_right();
			key_pressed = true;
		}

		window.clear();
		window.draw(zmija.head);
		window.draw(zmija.body);
		window.draw(collisionShape.colisionShape);
		window.display();
	}

	return 0;
}

