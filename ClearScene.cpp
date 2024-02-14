#include "Novice.h"
#include "ClearScene.h"

void ClearScene::Init() {}

void ClearScene::Update() {
	SceneChangeTimer--;
	if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE] && SceneChangeTimer <= 0) {
		sceneNo = kTitle;
		SceneChangeTimer = 10;
	}
}

void ClearScene::Draw() { Novice::ScreenPrintf(1280 / 2, 720 / 2, "ClearScene"); }
