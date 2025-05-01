#pragma once
#include "shape.h"

class Circle : public Shape
{
public:
	Circle() = default;
	Circle(Vector2& position, Color& color = WHITE, float size = 20)
		: Shape(position, color, size) {
	}

	void Update() override;
	void Draw() override;
	Type GetType() const override { return Type::Circle; }
};