#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(float w, float h) { m_width = w; m_height = h; }
	~Rectangle() {}
	float Area() const override {
		return m_width * m_height;
	}
	void SetWidth(float width) { m_width = width; }
	void SetHeight(float height) { m_height = height; }
	float GetWidth() const { return m_width; }
	float GetHeight() const { return m_height; }
private:
	float m_width;
	float m_height;
};