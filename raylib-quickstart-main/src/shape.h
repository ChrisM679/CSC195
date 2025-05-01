#pragma once
#include "raylib.h"

class Shape
{
public:
	enum class Type
	{
		Circle,
		Square
	};

public:
	Shape() = default;
	Shape(Vector2& position, Color& color = WHITE, float size = 20)
		: m_position(position), m_color(color), m_size(size) {
	}
	
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual Type GetType() const = 0;

	const Vector2& GetPosition() const { return m_position; }	
	void SetPosition(const Vector2& position) { m_position = position; }

	const Color& GetColor() const { return m_color; }
	void SetColor(const Color& color) { m_color = color; }

	float GetSize() const { return m_size; }
	void SetSize(float size) { m_size = size; }

protected:
	Vector2 m_position = { 0, 0 };
	Color m_color = WHITE;
	float m_size = 20;
};