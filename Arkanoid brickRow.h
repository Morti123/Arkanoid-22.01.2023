#pragma once
#include "settings.h" 
#include "SFML/Graphics.hpp" 
#include "Break.h" 
struct BrickRow {
	Brick arr[20];
	int size;
};
void brickRowInit(BrickRow& brickrow, int size, sf::Vector2f position, float stepX) {
	brickrow.size = size;
	for (int i = 0; i < brickrow.size; i++) {
		sf::Color color{ (sf::Uint8)(rand() % 256),(sf::Uint8)(rand() % 256),(sf::Uint8)(rand() % 256) };
		sf::Vector2f brickPos(position.x + i * stepX, position.y);
		brickInit(brickrow.arr[i], color, brickPos);
	}
}
void brickRowUpdate(BrickRow& brickrow){
	for (int i = 0; i < brickrow.size; i++) {
		brickUpdate(brickrow.arr[i]);
	}
}
void brickRowDraw(sf::RenderWindow& window, const BrickRow& brickrow) {
	for (int i = 0; i < brickrow.size; i++) {
		brickDraw(window, brickrow.arr[i]);
	}
}

