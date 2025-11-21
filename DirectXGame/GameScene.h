#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;
class GameScene
{
public:
	GameScene() = default;
	~GameScene();
	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();
private:
	DirectXCommon* dxCommon_ = nullptr; // DirectXCommonのインスタンス

	// エフェクト3Dモデルデータ
	Model* modelEffect_ = nullptr;

	Camera camera_;
	Input* input_ = nullptr;

	float bgPosX1_;     // 背景 A の現在 X座標
    float bgPosX2_;     // 背景 B の現在 X座標
	float bgPosX3_;     // 背景 C の現在 X座標
	float bgPosX4_;     // 背景 D の現在 X座標
    float bgSpeed_;     // 背景スクロール速度
	uint32_t textureHandle_ = 0;
	uint32_t textureHandle2_ = 0;
	Sprite* backGroundSprite_ = nullptr; //背景の画像
	Sprite* backGroundSprite2_ = nullptr; //背景の画像2
};

