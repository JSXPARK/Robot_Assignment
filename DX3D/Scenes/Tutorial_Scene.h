#pragma once

class Tutorial_Scene : public Scene
{
public:
	Tutorial_Scene();
	~Tutorial_Scene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void GUIRender() override;

private:
	MatrixBuffer* worldBuffer;
	MatrixBuffer* viewBuffer;
	MatrixBuffer* projectionBuffer;

	VertexShader* vertexShader;
	PixelShader* pixelShader;

	VertexBuffer* vertexBuffer;
	IndexBuffer* indexBuffer;

	vector<VertexColor> vertices;
	vector<UINT> indices;

	Matrix world;
};