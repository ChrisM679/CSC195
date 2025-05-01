#pragma once
#include "shape.h"
#include <vector>

class Editor
{
public:
	Editor();
	~Editor();

	void Update();
	void Draw();

private:
	float m_size = 20;
	Shape::Type m_type = Shape::Type::Circle;
	const Color m_color[7] = { WHITE, GREEN, RED, BLUE, PURPLE, SKYBLUE, MAGENTA };
	int m_colorIndex = 0;

	Shape* m_shape = nullptr;
	std::vector<Shape*> m_shapes;
};