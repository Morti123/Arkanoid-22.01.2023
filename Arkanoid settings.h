#pragma once
#include <SFML/Graphics.hpp> 
const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 60.f;

const float size = 8.f;
 sf::Vector2f brickRowStartPos{ 0.f, 0.f };
const float stepX = 100.f;
float BatSpeedX;
const float batWidth = 80.f;
const float batHeight = 20.f;
const float batOffset = 50.f;
const sf::Vector2f batSize(80.f, 20.f);
const sf::Color batColor{ sf::Color::White };
const float batSpeed = 5.f;
const sf::Vector2f batStartPos{ (WINDOW_WIDTH - 3 * batWidth) / 2, WINDOW_HEIGHT - 2 * batHeight };
const float BALL_RADIUS = 25.f;
const sf::Color BALL_COLOR{ sf::Color::White };
const sf::Vector2f ballStartPos{ (WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,
  (WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2
};
const int CHAR_SIZE = 64;
const sf::Vector2f TextStartPos{ 20.f, 10.f };
const float BRICK_WIDTH = 100.f;
const float BRICK_HEIGHT = 30.f;
const sf::Color Brick_Color{ sf::Color::Red };
