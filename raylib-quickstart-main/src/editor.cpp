#include "editor.h"
#include "square.h"
#include "circle.h"

Editor::Editor()
{
}

Editor::~Editor()
{
}

void Editor::Update()
{
	if (IsKeyDown(KEY_RIGHT)) m_size += 0.5f;
	if (IsKeyDown(KEY_LEFT)) m_size -= 0.5f;

	m_shape->SetSize(m_size);

	if (IsMouseButtonPressed(0))
	{
		//add curent shape
		m_shapes.push_back(m_shape);
		//create new shape
		m_shape = new Circle(Vector2{ 400, 400 });
	}

	m_shape->SetPosition(GetMousePosition());

	for (auto& shape : m_shapes)
	{
		shape->Update();
	}

	m_shape->Update();
}

void Editor::Draw()
{
	for (auto& shape : m_shapes)
	{
		shape->Draw();
	}


}
