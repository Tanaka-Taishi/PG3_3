#include"TitleScene.h"
#include"Novice.h"

void TitleScene::Init(){}

void TitleScene::Update() {
	SceneChangeTimer--;

	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE] && SceneChangeTimer <= 0) {
		sceneNo = kStage;
		SceneChangeTimer = 10;
		isBullet = false;
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(1280 / 2, 720 / 2, "TitleScene");
}
