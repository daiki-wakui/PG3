#pragma once

//ゲームシーン
enum GameScene
{
	GAME_TITLE,
	NEW_GAME,
	GAME_PLAY,
	GAME_CLEAR
};

class SceneManager final{
private:

	//コンストラクタ
	SceneManager();
	//デストラクタ
	~SceneManager();

	//シーン番号
	int sceneNo;

public:

	//コピーコンストラクタを無効
	SceneManager(const SceneManager& obj) = delete;
	//代入演算子を無効
	SceneManager& operator=(const SceneManager& obj) = delete;

	void ChangeScene(int nextSceneNo);

	static SceneManager* GetInstance();
	int GetSceneNo() { return sceneNo; };
};

