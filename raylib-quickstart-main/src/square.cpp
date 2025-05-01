#include "square.h"

void Square::Update()
{
}

void Square::Draw()
{
	DrawRectangleV(m_position, Vector2{ m_size, m_size }, m_color);
}