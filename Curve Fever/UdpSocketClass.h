#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>

class UdpSocketClass1 : sf::Socket {
public:
	sf::UdpSocket *socket;

	UdpSocketClass1();

	void BindOnPort() {

	}



};
