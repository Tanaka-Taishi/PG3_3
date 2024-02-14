#include"StageScene.h"
#include"Novice.h"

void StageScene::Init() {}

void StageScene::Update() {
	SceneChangeTimer--;
	if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE] && SceneChangeTimer <= 0 || enemyLife <= 0) {
		sceneNo = kClear;
		SceneChangeTimer = 10;

		
		enemyPosX = 640;
		enemyPosY = 360;

		playerPosX = 640;
		playerPosY = 540;

		enemyLife = 5;

		bulletPosX = -100;
		bulletPosY = -100;


	}
	enemyPosX += enemySpeedX;
	if (enemyPosX <= 0 || enemyPosX >= 1280) {
		enemySpeedX *= -1;
	}
	enemyPosY += enemySpeedY;
	if (enemyPosY <= 0 || enemyPosY >= 720) {
		enemySpeedY *= -1;
	}
	if (keys_[DIK_A] && preKeys_[DIK_A]) {
		playerPosX -= playerSpeedX;
	}
	if (keys_[DIK_D] && preKeys_[DIK_D]) {
		playerPosX += playerSpeedX;
	}
	if (keys_[DIK_W] && preKeys_[DIK_W]) {
		playerPosY -= playerSpeedY;
	}
	if (keys_[DIK_S] && preKeys_[DIK_S]) {
		playerPosY += playerSpeedY;
	}

	 
	if (keys_[DIK_RETURN] && preKeys_[DIK_RETURN] == 0) {
		if (!isBullet) {
			isBullet = true;
			bulletPosX = playerPosX;
			bulletPosY = playerPosY;
		}
	}
	if (isBullet) {
		bulletPosY -= bulletSpeed;
		if (bulletPosY <= 0) {
			isBullet = false;
		}
	}

	if (isBullet == false) {
		bulletPosX = -100;
		bulletPosY = -100;
	}

	if (bulletPosY <= 0) {
		isBullet = false;
	}
	if (enemyLife > 0) {
		int e2bX = enemyPosX - bulletPosX;
		int E2BY = enemyPosY - bulletPosY;

		eAndbR = enemyRadius + bulletRadius;

		if (e2bX * e2bX + E2BY * E2BY <= eAndbR * eAndbR) {
			enemyLife -= 1;
			isBullet = false;
		}
	}

}

void StageScene::Draw() { 
	Novice::ScreenPrintf(1280 / 2, 720 / 2, "StageScene");
	Novice::DrawEllipse(
		playerPosX,playerPosY,
		playerRadius,playerRadius
		,0.0f,WHITE,kFillModeSolid);
	Novice::DrawEllipse(
	    bulletPosX, bulletPosY, 
		bulletRadius, bulletRadius, 
		0.0f, WHITE, kFillModeSolid);
	if (enemyLife == 5 || enemyLife == 4) {
		Novice::DrawEllipse(
		    enemyPosX, enemyPosY, enemyRadius, enemyRadius, 0.0f, WHITE, kFillModeSolid);
	} else if (enemyLife == 3 || enemyLife == 2) {
		Novice::DrawEllipse(
		    enemyPosX, enemyPosY, 
			enemyRadius, enemyRadius, 
			0.0f, BLUE, kFillModeSolid);
	} else if (enemyLife == 1) {
		Novice::DrawEllipse(
		    enemyPosX, enemyPosY,
			enemyRadius, enemyRadius, 
			0.0f, RED, kFillModeSolid);
	}
}

