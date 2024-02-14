#pragma once
#include "IScene.h"

class StageScene : public IScene {
public:
	void Init()override;
	void Update()override;
	void Draw() override;
};