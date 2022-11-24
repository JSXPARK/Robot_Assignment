#include "Framework.h"

Cube::Cube(Vector3 _size) : size(_size)
{
	material = new Material(L"Shaders/Texture.hlsl");
	material->SetDiffuseMap(L"Textures/Landscape/Box.png");

	CreateMesh();

	worldBuffer = new MatrixBuffer();

	/*worldMatrix._11 = 1;
	worldMatrix._22 = 1;
	worldMatrix._33 = 1;
	worldMatrix._44 = 1;*/
}

Cube::~Cube()
{
	delete material;
	delete mesh;
	delete worldBuffer;
}

//void Cube::Update()
//{
//	static float angle = 0.0f;
//
//	if (GetAsyncKeyState('A'))
//		angle -= 0.01f;
//	if (GetAsyncKeyState('D'))
//		angle += 0.01f;
//
//	worldMatrix._22 = +cos(angle);
//	worldMatrix._33 = +cos(angle);
//	worldMatrix._23 = -sin(angle);
//	worldMatrix._32 = +sin(angle);
//
//	world = XMLoadFloat4x4(&worldMatrix);
//}

void Cube::Render()
{
	worldBuffer->Set(world);

	worldBuffer->SetVSBuffer(0);

	mesh->IASet();
	material->Set();

	DC->DrawIndexed(indices.size(), 0, 0);
}

void Cube::CreateMesh()
{
	Vector3 halfSize = size * 0.5f;

	vertices.resize(24);

	vertices[0].pos = {-halfSize.x, +halfSize.y, -halfSize.z}; // 0
	vertices[1].pos = {+halfSize.x, +halfSize.y, -halfSize.z}; // 1
	vertices[2].pos = {-halfSize.x, -halfSize.y, -halfSize.z}; // 2
	vertices[3].pos = {+halfSize.x, -halfSize.y, -halfSize.z}; // 3

	vertices[4].pos = {-halfSize.x, +halfSize.y, +halfSize.z}; // 4
	vertices[5].pos = {+halfSize.x, +halfSize.y, +halfSize.z}; // 5
	vertices[6].pos = {-halfSize.x, +halfSize.y, -halfSize.z}; // 6
	vertices[7].pos = {+halfSize.x, +halfSize.y, -halfSize.z}; // 7

	vertices[8].pos = {+halfSize.x, +halfSize.y, +halfSize.z}; // 8
	vertices[9].pos = {+halfSize.x, -halfSize.y, +halfSize.z}; // 9
	vertices[10].pos = {+halfSize.x, +halfSize.y, -halfSize.z}; // 10
	vertices[11].pos = {+halfSize.x, -halfSize.y, -halfSize.z}; // 11

	vertices[12].pos = {+halfSize.x, +halfSize.y, +halfSize.z}; // 12
	vertices[13].pos = {-halfSize.x, +halfSize.y, +halfSize.z}; // 13
	vertices[14].pos = {+halfSize.x, -halfSize.y, +halfSize.z}; // 14
	vertices[15].pos = {-halfSize.x, -halfSize.y, +halfSize.z}; // 15

	vertices[16].pos = {-halfSize.x, -halfSize.y, +halfSize.z}; // 16
	vertices[17].pos = {-halfSize.x, +halfSize.y, +halfSize.z}; // 17
	vertices[18].pos = {-halfSize.x, -halfSize.y, -halfSize.z}; // 18
	vertices[19].pos = {-halfSize.x, +halfSize.y, -halfSize.z}; // 19

	vertices[20].pos = {-halfSize.x, -halfSize.y, -halfSize.z}; // 20
	vertices[21].pos = {+halfSize.x, -halfSize.y, -halfSize.z}; // 21
	vertices[22].pos = {-halfSize.x, -halfSize.y, +halfSize.z}; // 22
	vertices[23].pos = {+halfSize.x, -halfSize.y, +halfSize.z}; // 23

	vertices[0].uv = { 0.f, 0.f };
	vertices[1].uv = { 1.f, 0.f };
	vertices[2].uv = { 0.f, 1.f };
	vertices[3].uv = { 1.f, 1.f };

	vertices[4].uv = { 0.f, 0.f };
	vertices[5].uv = { 0.f, 0.f };
	vertices[6].uv = { 0.f, 0.f };
	vertices[7].uv = { 0.f, 0.f };

	vertices[8].uv = { 0.f, 0.f };
	vertices[9].uv = { 0.f, 0.f };
	vertices[10].uv = { 0.f, 0.f };
	vertices[11].uv = { 0.f, 0.f };

	vertices[12].uv = { 0.f, 0.f };
	vertices[13].uv = { 0.f, 0.f };
	vertices[14].uv = { 0.f, 0.f };
	vertices[15].uv = { 0.f, 0.f };

	vertices[16].uv = { 0.f, 0.f };
	vertices[17].uv = { 0.f, 0.f };
	vertices[18].uv = { 0.f, 0.f };
	vertices[19].uv = { 0.f, 0.f };

	vertices[20].uv = { 0.f, 0.f };
	vertices[21].uv = { 0.f, 0.f };
	vertices[22].uv = { 0.f, 0.f };
	vertices[23].uv = { 0.f, 0.f };

	indices =
	{
		 0,  1,  2,  1,  3,  2, // front
		 4,  5,  6,  5,  7,  6, // top
		 8,  9, 10,  9, 11, 10, // right
		12, 13, 14, 13, 15, 14, // back
		16, 17, 18, 17, 19, 18, // left
		20, 21, 22, 21, 23, 22  // bottom
	};

	mesh = new Mesh(vertices.data(), sizeof(VertexType), vertices.size(), indices.data(), indices.size());
}