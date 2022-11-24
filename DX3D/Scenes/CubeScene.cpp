#include "Framework.h"
#include "CubeScene.h"

CubeScene::CubeScene()
{
	s = new Cube({ 0.1f, 0.1f, 0.1f });
	s->SetPivot(0.f, 0.f, 0.f);

	Body = new Cube({1.5f,2.f,1.f});
	Body->GetMaterial()->SetDiffuseMap(L"Textures/UV/Body.png");
	Body->SetParent(s);
	Body->position.y = -1.5f;

	Head = new Cube({ 1.5f, 1.f, 1.f });
	Head->SetParent(Body);
	Head->GetMaterial()->SetDiffuseMap(L"Textures/UV/Head.png");
	Head->position.y = +1.5f;

	Left_Ear = new Cube(Vector3(0.4f,0.4f,0.9f));
	Left_Ear->SetParent(Head);
	Left_Ear->GetMaterial()->SetDiffuseMap(L"Textures/UV/Base.png");
	Left_Ear->position.x = +0.21f;
	Left_Ear->position.y = +0.45f;
	Left_Ear->rotation.z = +180;

	Right_Ear = new Cube(Vector3(0.4f, 0.4f, 0.9f));
	Right_Ear->SetParent(Head);
	Right_Ear->GetMaterial()->SetDiffuseMap(L"Textures/UV/Base.png");
	Right_Ear->position.x = -0.21f;
	Right_Ear->position.y = +0.45f;
	Right_Ear->rotation.z = -180;

	Left_arm = new Cube({1.2f, 0.5f, 0.5f});
	Left_arm->SetParent(Body);
	Left_arm->GetMaterial()->SetDiffuseMap(L"Textures/UV/Base.png");
	Left_arm->position.x = 1.f;
	Left_arm->position.y = 0.5f;
	Left_arm->position.z = -0.5f;
	Left_arm->rotation.y = +45.f;
	Left_arm->rotation.z = -10.f;

	Right_arm = new Cube({ 1.2f, 0.5f, 0.5f });
	Right_arm->SetParent(Body);
	Right_arm->GetMaterial()->SetDiffuseMap(L"Textures/UV/Base.png");
	Right_arm->position.x = -1.f;
	Right_arm->position.y = 0.5f;
	Right_arm->position.z = -0.5f;
	Right_arm->rotation.y = -45.f;
	Right_arm->rotation.z = +10.f;

	Left_Hand = new Cube({ 0.3f, 0.5f, 0.5f });
	Left_Hand->SetParent(Left_arm);
	Left_Hand->GetMaterial()->SetDiffuseMap(L"Textures/UV/Skin.png");
	Left_Hand->position.x = -0.75f;

	Right_Hand = new Cube({ 0.3f, 0.5f, 0.5f });
	Right_Hand->SetParent(Right_arm);
	Right_Hand->GetMaterial()->SetDiffuseMap(L"Textures/UV/Skin.png");
	Right_Hand->position.x = +0.75f;

	Left_Leg = new Cube({ 0.7f, 1.f, 1.f });
	Left_Leg->SetParent(Body);
	Left_Leg->GetMaterial()->SetDiffuseMap(L"Textures/UV/Base.png");
	Left_Leg->position.x = +0.4f;
	Left_Leg->position.y = -1.5f;
	Left_Leg->SetPivot(0.f, 1.f, 0.f);

	Right_Leg = new Cube({ 0.7f, 1.f, 1.f });
	Right_Leg->SetParent(Body);
	Right_Leg->GetMaterial()->SetDiffuseMap(L"Textures/UV/Base.png");
	Right_Leg->position.x = -0.4f;
	Right_Leg->position.y = -1.5f;
	Right_Leg->SetPivot(0.f, 1.f, 0.f);

	Left_Foot = new Cube({ 0.7f, 0.3f, 1.f });
	Left_Foot->SetParent(Left_Leg);
	Left_Foot->GetMaterial()->SetDiffuseMap(L"Textures/UV/Skin.png");
	Left_Foot->position.y = -0.7f;

	Right_Foot = new Cube({ 0.7f, 0.3f, 1.f });
	Right_Foot->SetParent(Right_Leg);
	Right_Foot->GetMaterial()->SetDiffuseMap(L"Textures/UV/Skin.png");
	Right_Foot->position.y = -0.7f;
}

CubeScene::~CubeScene()
{
	delete Body;
	delete Head;
	delete Left_Ear;
	delete Right_Ear;
	delete Left_arm;
	delete Right_arm;
	delete Left_Hand;
	delete Right_Hand;
	delete Left_Leg;
	delete Right_Leg;
	delete Left_Foot;
	delete Right_Foot;

	delete vertexBuffer;
	delete indexBuffer;
	delete worldBuffer;
	delete viewBuffer;
	delete projectionBuffer;
}

void CubeScene::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		s->position.z -= s->Forward().z * 0.0005f;
		s->position.x -= s->Forward().x * 0.0005f;

		if (GetAsyncKeyState(VK_LEFT))
		{
			s->rotation.y -= 0.0009f;
			s->position.x += s->Right().x * 0.0005f;
			s->position.z += s->Right().z * 0.0005f;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			s->rotation.y += 0.0009f;
			s->position.x -= s->Right().x * 0.0005f;
			s->position.z -= s->Right().z * 0.0005f;
		}

		if (Right_Leg->rotation.x >= XM_PIDIV4) TURN = -1;
		else if (Right_Leg->rotation.x <= -XM_PIDIV4) TURN = 1;

		Right_Leg->rotation.x += 0.0005f * TURN;
		Left_Leg->rotation.x -= 0.0005f * TURN;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		s->position.z += s->Forward().z * 0.0005f;
		s->position.x += s->Forward().x * 0.0005f;

		if (GetAsyncKeyState(VK_LEFT))
		{
			s->rotation.y -= 0.0009f;
			s->position.x += s->Right().x * 0.0005f;
			s->position.z += s->Right().z * 0.0005f;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			s->rotation.y += 0.0009f;
			s->position.x -= s->Right().x * 0.0005f;
			s->position.z -= s->Right().z * 0.0005f;
		}

		if (Right_Leg->rotation.x >= XM_PIDIV4) TURN = -1;
		else if (Right_Leg->rotation.x <= -XM_PIDIV4) TURN = 1;

		Right_Leg->rotation.x += 0.0005f * TURN;
		Left_Leg->rotation.x -= 0.0005f * TURN;
	}
	else if (!GetAsyncKeyState(VK_UP) and !GetAsyncKeyState(VK_DOWN) and GetAsyncKeyState(VK_LEFT))
	{
		s->rotation.y -= 0.0009f;
	}
	else if (!GetAsyncKeyState(VK_UP) and !GetAsyncKeyState(VK_DOWN) and GetAsyncKeyState(VK_RIGHT))
	{
		s->rotation.y += 0.0009f;
	}
	else
	{
		Right_Leg->rotation.x = 0.f;
		Left_Leg->rotation.x = 0.f;
	}

	s->UpdateWorld();
	Body->UpdateWorld();
	Head->UpdateWorld();
	Left_Ear->UpdateWorld();
	Right_Ear->UpdateWorld();
	Left_arm->UpdateWorld();
	Right_arm->UpdateWorld();
	Left_Hand->UpdateWorld();
	Right_Hand->UpdateWorld();
	Left_Leg->UpdateWorld();
	Right_Leg->UpdateWorld();
	Left_Foot->UpdateWorld();
	Right_Foot->UpdateWorld();

	//cube->Update();
}

void CubeScene::Render()
{
	s->Render();
	Body->Render();
	Head->Render();
	Left_Ear->Render();
	Right_Ear->Render();
	Left_arm->Render();
	Right_arm->Render();
	Left_Hand->Render();
	Right_Hand->Render();
	Left_Leg->Render();
	Right_Leg->Render();
	Left_Foot->Render();
	Right_Foot->Render();
}

void CubeScene::GUIRender()
{
}