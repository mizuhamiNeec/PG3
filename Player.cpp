#include "Player.h"

#include <algorithm>
#include <cassert>
#include <format>
#include <imgui.h>

Player::~Player() {
}

void Player::Initialize(Model* model, uint32_t textureHandle) {
	// ヌルポチェック
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;
	// 引数の内容をメンバ変数に記録
	worldTransform_.Initialize();

	// シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
}

void Player::Update() {

	// 行列を定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void Player::Draw(const ViewProjection& viewProjection) const {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

void Player::MoveRight() {
	worldTransform_.translation_.x += speed_;
}

void Player::MoveLeft() {
	worldTransform_.translation_.x -= speed_;
}

