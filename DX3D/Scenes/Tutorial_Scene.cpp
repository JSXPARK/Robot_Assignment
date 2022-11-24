#include "Framework.h"
#include "Tutorial_Scene.h"

Tutorial_Scene::Tutorial_Scene()
{
	vertexShader = Shader::AddVS(L"Shaders/Tutorial.hlsl");
	pixelShader = Shader::AddPS(L"Shaders/Tutorial.hlsl");

	// ����(Vertex) : 3D���������� �� ��
	// Polygon : ���� 3���� �̷���� 3���� ���������� �ﰢ��
	// ���� ������ ���� �ð������ �ո��̸�, �ո鸸 ���
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