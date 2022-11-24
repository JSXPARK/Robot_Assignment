#pragma once

class CubeScene : public Scene
{
public:
	 CubeScene();
	~CubeScene();

	virtual void Update()    override;
	virtual void Render()    override;
	virtual void GUIRender() override;

private:
	Cube* Head;
	Cube* Left_Ear;
	Cube* Right_Ear;
	Cube* Body;
	Cube* Left_arm;
	Cube* Right_arm;
	Cube* Left_Hand;
	Cube* Right_Hand;
	Cube* Left_Leg;
	Cube* Right_Leg;
	Cube* Left_Foot;
	Cube* Right_Foot;
	Cube* s;

	int TURN = 1;

	MatrixBuffer* worldBuffer;
	MatrixBuffer* viewBuffer;
	MatrixBuffer* projectionBuffer;

	VertexShader* vertexShader;
	PixelShader* pixelShader;

	VertexBuffer* vertexBuffer;
	IndexBuffer* indexBuffer;

	Matrix world;
	Float4x4 worldMatrix;
};