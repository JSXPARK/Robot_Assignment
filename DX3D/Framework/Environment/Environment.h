#pragma once

class Environment : public Singleton<Environment>
{
public:
	Environment();
	~Environment();

private:
	void CreateProjection();
	void SetViewport();
	void CreateStates();

private:
	MatrixBuffer* viewBuffer;
	MatrixBuffer* projectionBuffer;

	SamplerState* samplerState;
};