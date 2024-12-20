#pragma once
#include "Input.h"
#include "Model.h"
#include "WorldTransform.h"

class Player {
public:
	~Player();

	void Initialize(Model* model, uint32_t textureHandle);
	void Update();
	void Draw(const ViewProjection& viewProjection) const;

	// メンバ関数
	void MoveRight();
	void MoveLeft();

private: // メンバ園数
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	// キーボード入力
	Input* input_ = nullptr;

	float speed_ = 1.0f;
};
