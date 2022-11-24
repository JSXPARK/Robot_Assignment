#include "Framework.h"
#include "Tutorial_Scene.h"

Tutorial_Scene::Tutorial_Scene()
{
	vertexShader = Shader::AddVS(L"Shaders/Tutorial.hlsl");
	pixelShader = Shader::AddPS(L"Shaders/Tutorial.hlsl");

	// 정점(Vertex) : 3D공간에서의 한 점
	// Polygon : 정점 3개로 이루어진 3차원 공간에서의 삼각형
	// 정점 순서에 따라서 시계방향이 앞면이며, 앞면만 출력
	vertices.emplace_back(-0.5f, -0.5f, 0.f, 1.f, 0.f, 0.f);
	vertices.emplace_back(+0.5f, +0.5f, 0.f, 0.f, 1.f, 0.f);
	vertices.emplace_back(+0.5f, -0.5f, 0.f, 0.f, 0.f, 1.f);
	vertices.emplace_back(-0.5f, +0.5f, 0.f, 1.f, 1.f, 0.f);

	vertexBuffer = new VertexBuffer(vertices.data(), sizeof(VertexColor), vertices.size());

	indices =
	{
		0, 1, 2, 0, 3, 1
	};

	indexBuffer = new IndexBuffer(indices.data(), indices.size());

	worldBuffer = new MatrixBuffer();
}

Tutorial_Scene::~Tutorial_Scene()
{
	delete vertexBuffer;
	delete indexBuffer;

	delete worldBuffer;
	delete viewBuffer;
	delete projectionBuffer;
}

void Tutorial_Scene::Update()
{
	static float angle = 0.f;

	angle += 0.001f;

	world = XMMatrixRotationX(angle) * XMMatrixRotationY(angle) * XMMatrixRotationZ(angle);

	worldBuffer->Set(world);
}

void Tutorial_Scene::Render()
{
	worldBuffer->SetVSBuffer(0);

	vertexBuffer->IASet(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	indexBuffer->IASet();

	vertexShader->Set();
	pixelShader->Set();

	DC->DrawIndexed(indices.size(), 0, 0);
}

void Tutorial_Scene::GUIRender() {}