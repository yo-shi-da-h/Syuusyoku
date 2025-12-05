#pragma once

#include "KamataEngine.h"
#include "MapChipField.h"
#include "Player.h"
#include "CameraController.h"
    // #include "Enemy.h"
using namespace KamataEngine;

class GameScene {
public:
	GameScene();
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

	void GenerateBlocks();

	void SwitchStage();
 

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	Player* player_ = nullptr;
	
	//Enemy* enemy_ = nullptr;

	MapChipField* mapChipField_;

	CameraController* cameraController_ = nullptr;

	

	Vector3 enemyPos = {0, 3, 100};

	Model* modelPlayer_ = nullptr;
	Model* modelBlock_ = nullptr;
	
	
	//Model* modelSkydome_ = nullptr;

	Model* modelTable_ = nullptr;

	uint32_t textureHandle_ = 0;
	uint32_t textureHandle2_ = 0;
	uint32_t textureHandle3_ = 0;
	uint32_t textureHandle4_ = 0;
	uint32_t textureHandle5_ = 0;
	uint32_t textureHandle6_ = 0;
	uint32_t textureHandle7_ = 0;

	//Sprite* FrontGroundSprite_ = nullptr; //前景のスプライト
	//Sprite* BackGroundSprite_ = nullptr;//背景のスプライト

	
	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;
	

	Camera camera_;

	bool isDebugCameraActive_ = false;
	// デバックカメラ
	DebugCamera* debugCamera_ = nullptr;
};