#include "GameScene.h"


using namespace MathUtility;
GameScene::~GameScene()
{
	delete backGroundSprite_;
}
void GameScene::Initialize() {
	// 初期化処理
	dxCommon_ = KamataEngine::DirectXCommon::GetInstance();
	input_ = KamataEngine::Input::GetInstance();
	
	textureHandle_ = KamataEngine::TextureManager::Load("miti2.png");
	backGroundSprite_ = Sprite::Create(textureHandle_, {0.0f,0.0f});
	textureHandle2_ = KamataEngine::TextureManager::Load("miti.png");
	backGroundSprite2_ = Sprite::Create(textureHandle2_, { 0.0f, 0.0f });

	float bgPox1 = 240.0f;
	float bgPox2 = 240.0f;
	/*float bgPox3 = 240.0f;
	float bgPox4 = 240.0f;*/
	bgPosX1_ = bgPox1;
	bgPosX2_ = bgPox2;
	/*bgPosX3_ = bgPox3;
	bgPosX4_ = bgPox4;*/
	bgSpeed_ = 4.0f; // スクロール速度の設定
    
}
void GameScene::Update() {
	// 更新処理
	 // フレーム時間を取得（デルタタイムを使って速度を時間あたりに）
	//float deltaTime = 1.0f / 60.0f; // 仮に60FPS固定とする
	// 背景のX座標を更新
	bgPosX1_ -= bgSpeed_;
	bgPosX2_ -= bgSpeed_;
	/*bgPosX3_ -= bgSpeed_;
	bgPosX4_ -= bgSpeed_;*/
	// 背景Aが画面外に出たら、背景Bの右側に配置
	if (bgPosX1_ <= -480.0f) {
		bgPosX1_ = bgPosX2_ + 1280.0f;
	}
	// 背景Bが画面外に出たら、背景Aの右側に配置
	if (bgPosX2_ <= -480.0f) {
		bgPosX2_ = bgPosX1_ + 1280.0f;
	}


	
   
}
void GameScene::Draw() {
	// 描画処理
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());
	 // 背景スプライトを 2枚描画
    backGroundSprite_->SetPosition({ bgPosX1_, 520.0f });
    backGroundSprite_->Draw();

    backGroundSprite2_->SetPosition({ bgPosX2_, 520.0f });
    backGroundSprite2_->Draw();

	
	Sprite::PostDraw();
}
