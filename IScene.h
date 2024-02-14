#pragma once
enum SceneType {
	kTitle,
	kStage,
	kClear,
	kSceneMax,
};

class IScene {
protected:
	static int sceneNo;
	char* keys_;
	char* preKeys_;
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();
	int GetSceneNo();

	void SetKeys(char* keys, char* preKeys_);
	int SceneChangeTimer = 10;

	int enemyPosX = 640;
	int enemyPosY = 360;

	int playerPosX = 640;
	int playerPosY = 540;

	int enemyLife = 5;

	int bulletPosX = -100;
	int bulletPosY = -100;
	int isBullet = false;

	
	int enemySpeedX = 10;
	int enemySpeedY = 10;

	int playerSpeedX = 10;
	int playerSpeedY = 10;

	int enemyRadius = 32;

	int playerRadius = 16;

	
	int bulletRadius = 8;

	int bulletSpeed = 15;

	int eAndbR = 0;
};
