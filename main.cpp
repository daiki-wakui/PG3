#include "DxLib.h"
#include "SceneManager.h"
#include "Player.h"
#include "Enemy.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LE2A_23_ワクイダイキ";

// ウィンドウ横幅
const int WIN_WIDTH = 1280;

// ウィンドウ縦幅
const int WIN_HEIGHT = 720;

bool Enemy::isAlive;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言
	SceneManager* gameScene = SceneManager::GetInstance();
	int sceneNo = GAME_PLAY;

	Player* player = new Player;
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;
	Enemy* enemy3 = new Enemy;

	//敵を配置
	enemy1->Initalize(300, 100);
	enemy2->Initalize(640, 100);
	enemy3->Initalize(900, 100);

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {

		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//
		// 更新処理

		//シーン番号を取得
		sceneNo = gameScene->GetSceneNo();
		
		//gamePlayシーン
		if (sceneNo == GameScene::GAME_PLAY) {

			player->Update(keys, oldkeys);

			//攻撃したら敵は死ぬ
			if (player->GetIsAttack() == true) {
				enemy1->Dead();
			}
		}

		// 描画処理
		//gamePlayシーン
		if (sceneNo == GameScene::GAME_PLAY) {
			player->Draw();
			enemy1->Draw();
			enemy2->Draw();
			enemy3->Draw();

			DrawFormatString(0, 0, GetColor(255, 255, 255), "SpaceKeyで攻撃");
		}

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	delete enemy1;
	delete enemy2;
	delete enemy3;
	delete player;
	// 正常終了
	return 0;
}
