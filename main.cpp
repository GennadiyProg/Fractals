#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

const float width = 700;
const float height = 700;

void DrawF(int x, int y, float len, float angle, RenderWindow& window) {
	VertexArray line(LinesStrip, 2);
	line[0].position = Vector2f(x, y);
	line[0].color = Color::Black;
	line[1].color = Color::Black;
	int x1, y1;
	x1 = x + sin(angle) * len / 2;
	y1 = y - cos(angle) * len / 2;
	line[1].position = Vector2f(x1, y1);
	window.draw(line);
	if (len > 20)
	{
		DrawF(x1, y1, len * 0.5, angle + 45, window);
		DrawF(x1, y1, len * 0.5, angle - 45, window);
		DrawF(x1, y1, len * 0.5, angle + 25, window);
		DrawF(x1, y1, len * 0.5, angle - 25, window);
	}
}

int main() {
	setlocale(LC_ALL, "Rus");

	RenderWindow window(VideoMode(width, height), "Fractal tree");
	int k = 0;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear(Color::White);

		DrawF(width / 2, height, 650, 0, window);

		window.display();
	}
}