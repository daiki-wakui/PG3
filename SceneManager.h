#pragma once

//�Q�[���V�[��
enum GameScene
{
	GAME_TITLE,
	NEW_GAME,
	GAME_PLAY,
	GAME_CLEAR
};

class SceneManager final{
private:

	//�R���X�g���N�^
	SceneManager();
	//�f�X�g���N�^
	~SceneManager();

	//�V�[���ԍ�
	int sceneNo;

public:

	//�R�s�[�R���X�g���N�^�𖳌�
	SceneManager(const SceneManager& obj) = delete;
	//������Z�q�𖳌�
	SceneManager& operator=(const SceneManager& obj) = delete;

	void ChangeScene(int nextSceneNo);

	static SceneManager* GetInstance();
	int GetSceneNo() { return sceneNo; };
};

