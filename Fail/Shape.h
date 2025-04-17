#pragma once

class Shape {
public:
	Shape() {}
	virtual ~Shape() {}
	virtual float Area() const = 0;
};