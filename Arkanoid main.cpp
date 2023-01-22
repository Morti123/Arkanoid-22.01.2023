#include "settings.h" 
#include "Function.h" 
#include "Textobj.h" 
#include "BALL.h" 
#include "BAT.h" 
#include "Break.h" 
#include "brickRow.h"
using namespace sf;
int main()
{
	srand(time(nullptr));
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	Bat bat;
	initBat(bat, batColor, batStartPos);
	float BatSpeedX = 0.f;
	Ball ball;
	ballInit(ball);
	TextObj scoreText;
	initText(scoreText, ball.Score);
	Brick brick;
	brickInit(brick, Brick_Color, brickRowStartPos);
	BrickRow brickrow;
	brickRowInit(brickrow, size, brickRowStartPos, stepX);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		brickUpdate(brick);
		ballUpdate(ball);
		batUpdate(bat);
		brickRowUpdate(brickrow);
		textUpdate(scoreText, ball.Score);
		if (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS)) {
			ball.speedy = -ball.speedy;
			window.close();
		}
		float ballX = ball.shape.getPosition().x;
		float ballY = ball.shape.getPosition().y;
		Vector2f midTop{ ballX + BALL_RADIUS,  ballY };
		Vector2f  mid{ ballX, ballY + BALL_RADIUS };
		Vector2f midBottom{ ballX + BALL_RADIUS,  ballY + 2 * BALL_RADIUS };
		if (pointInRect(bat.shape, mid)) {
			ball.speedx = -ball.speedx;
			ball.Score++;
		}
		if (pointInRect(bat.shape, midBottom)) {
			ball.speedy = -ball.speedy;
			ball.Score++;
		}
		if (pointInRect(bat.shape, midTop)) {
			ball.speedy = -ball.speedy;
			ball.Score++;
		}
		window.clear(sf::Color::Black);
		brickRowDraw(window, brickrow);
		ballDraw(window, ball);
		batDraw(window, bat);
		brickDraw(window, brick);
		textDraw(window, scoreText);
		window.display();
	}

	return 0;
}