#include "DxLib.h"
#include "SceneManager.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LE2A_23_ワクイダイキ";

// ウィンドウ横幅
const int WIN_WIDTH = 1280;

// ウィンドウ縦幅
const int WIN_HEIGHT = 720;

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
	int sceneNo = GAME_TITLE;

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

		//gameTitleシーン
		if (sceneNo == GameScene::GAME_TITLE) {

			//spaceKeyで次のシーンへ
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				gameScene->ChangeScene(GameScene::NEW_GAME);
			}

		}
		//newGameシーン
		if (sceneNo == GameScene::NEW_GAME) {

			//spaceKeyで次のシーンへ
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				gameScene->ChangeScene(GameScene::GAME_PLAY);
			}

		}
		//gamePlayシーン
		if (sceneNo == GameScene::GAME_PLAY) {

			//spaceKeyで次のシーンへ
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				gameScene->ChangeScene(GameScene::GAME_CLEAR);
			}
		}
		//gameClearシーン
		if (sceneNo == GameScene::GAME_CLEAR) {

			//spaceKeyで次のシーンへ
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				gameScene->ChangeScene(GameScene::GAME_TITLE);
			}

		}


		// 描画処理
		//gameTitleシーン
		if (sceneNo == GameScene::GAME_TITLE) {
			DrawBox(0, 0, 1280, 720, GetColor(255, 125, 125), true);
			DrawFormatString(0, 0, GetColor(255, 255, 255), "sceneNo : %d", sceneNo);
			DrawFormatString(0, 20, GetColor(255, 255, 255), "SpaceKeyでシーン切り替え");
		}
		//newGameシーン
		if (sceneNo == GameScene::NEW_GAME) {
			DrawBox(0, 0, 1280, 720, GetColor(125, 255, 125), true);
			DrawFormatString(0, 0, GetColor(255, 255, 255), "sceneNo : %d", sceneNo);
			DrawFormatString(0, 20, GetColor(255, 255, 255), "SpaceKeyでシーン切り替え");
		}
		//gamePlayシーン
		if (sceneNo == GameScene::GAME_PLAY) {
			DrawBox(0, 0, 1280, 720, GetColor(125, 125, 255), true);
			DrawFormatString(0, 0, GetColor(255, 255, 255), "sceneNo : %d", sceneNo);
			DrawFormatString(0, 20, GetColor(255, 255, 255), "SpaceKeyでシーン切り替え");
		}
		//gameClearシーン
		if (sceneNo == GameScene::GAME_CLEAR) {
			DrawBox(0, 0, 1280, 720, GetColor(125, 125, 125), true);
			DrawFormatString(0, 0, GetColor(255, 255, 255), "sceneNo : %d", sceneNo);
			DrawFormatString(0, 20, GetColor(255, 255, 255), "SpaceKeyでシーン切り替え");
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

	// 正常終了
	return 0;
}
