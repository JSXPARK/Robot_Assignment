#include "Framework.h"

Material::Material()
	: vertexShader(nullptr), pixelShader(nullptr)
{
}

Material::Material(wstring shaderFile)
{
	SetShader(shaderFile);
}

Material::~Material()
{
}

void Material::SetShader(wstring file)
{
	vertexShader = Shader::AddVS(file);
	pixelShader = Shader::AddPS(file);
}

void Material::SetDiffuseMap(wstring file)
{
	diffuseMap = Texture::Add(file);
}

void Material::Set()
{
	if (diffuseMap)
		diffuseMap->PSSet(0);

	vertexShader->Set();
	pixelShader->Set();
}
