#include <Novice.h>
#include"GameManager.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	GameManager* gameManager = new GameManager();


	// キー入力結果を受け取る箱
	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
