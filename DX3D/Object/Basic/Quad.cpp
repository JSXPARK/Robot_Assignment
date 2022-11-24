#include "Framework.h"

Quad::Quad(float width, float height) : width(width), height(height)
{
	material = new Material(L"Shaders/Texture.hlsl");
	material->SetDiffuseMap(L"Textures/Landscape/Box.png");

	CreateMesh();

	worldBuffer = new MatrixBuffer();
}

Quad::~Quad()
{
	delete material;
	delete mesh;
	delete worldBuffer;
}

void Quad::Render()
{
	worldBuffer->SetVSBuffer(0);

	static float angle = 0.0f;

	angle += 0.001f;

	world = XMMatrixRotationX(angle) * XMMatrixRotationY(angle) * XMMatrixRotationZ(angle);
	worldBuffer->Set(world);

	mesh->IASet();
	material->Set();

	DC->DrawIndexed(indices.size(), 0, 0);
}

void Quad::CreateMesh()
{
	Float2 halfSize = { width * 0.5f, height * 0.5f };

	vertices.resize(4);
	vertices[0] = VertexType(-halfSize.x, +halfSize.y, -0.5f, 0.f, 0.f);
	vertices[1] = VertexType(+halfSize.x, +halfSize.y, -0.5f, 1.f, 0.f);
	vertices[2] = VertexType(-halfSize.x, -halfSize.y, -0.5f, 0.f, 1.f);
	vertices[3] = VertexType(+halfSize.x, -halfSize.y, -0.5f, 1.f, 1.f);

	indices =
	{
		 0,  1,  2,  1,  3,  2
	};

	mesh = new Mesh(vertices.data(), sizeof(VertexType), vertices.size(), indices.data(), indices.size());
}
