#pragma once
#include "settings.h" 
#include "SFML/Graphics.hpp" 
struct Bat {
	sf::RectangleShape shape;
	float speedx;
};
void batInit(Bat& bat) {
	bat.shape.setSize(batSize);
	bat.shape.setFillColor(batColor);
	bat.shape.setPosition(batStartPos);
}
void batReboundHorizontal(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { bat.shape.move(-5, 0); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { bat.shape.move(5, 0); }
	if (bat.shape.getPosition().x <= 0) {
		bat.shape.setPosition(0.f, WINDOW_HEIGHT - 2 * batHeight);
	}
	if (bat.shape.getPosition().x + batWidth >= WINDOW_WIDTH) {
		bat.shape.setPosition(WINDOW_WIDTH - batWidth, WINDOW_HEIGHT - 2 * batHeight);
	}
}
void batUpdate(Bat& bat) {
	bat.shape.move(0,BatSpeedX);
	batReboundHorizontal(bat);
}
void batDraw(sf::RenderWindow& window, Bat& bat) {
	window.draw(bat.shape);
}
