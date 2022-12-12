#include "SceneManager.h"

SceneManager::SceneManager()
{
	sceneNo = GAME_TITLE;
}

SceneManager::~SceneManager()
{
}

void SceneManager::ChangeScene(int nextSceneNo)
{
	sceneNo = nextSceneNo;
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;

	return &instance;
}
