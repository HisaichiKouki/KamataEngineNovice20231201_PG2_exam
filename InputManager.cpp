#include "InputManager.h"

InputManager* InputManager::GetInstance()
{
	static InputManager instance;
	return &instance;
}

void InputManager::Update()
{
	GetInstance()->_Update();
}



void InputManager::_Update()
{
	memcpy(keys,preKeys,256);
	Novice::GetHitKeyStateAll(keys);
	Novice::GetAnalogInputLeft(0, &inputStick.x, &inputStick.y);



}

bool InputManager::IsPressKey(int DIK)
{	
	return keys[DIK];
}

bool InputManager::IsReleaseKey(int DIK)
{
	return preKeys[DIK]&&!keys[DIK];
}


bool InputManager::IsTriggerKey(int DIK)
{
	return keys[DIK]&&!preKeys[DIK];
}
