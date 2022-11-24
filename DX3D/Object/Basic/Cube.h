#pragma once

class Cube : public Transform
{
private:
	typedef VertexUV VertexType;

public:
	 Cube(Vector3 _size = Vector3(1, 1, 1));
	~Cube();

	//void Update();
	void Render();

	Material* GetMaterial() { return material; }

private:
	void CreateMesh();

private:
	Vector3 size;

	Material* material;
	Mesh* mesh;

	MatrixBuffer* worldBuffer;

	vector<VertexType> vertices;
	vector<UINT> indices;

	//Matrix world;
	//Float4x4 worldMatrix;
};