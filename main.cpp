#include <cstdio>
#include <Windows.h>

class Enemy {
public:
	// メンバ関数ポインタのテーブル
	typedef void (Enemy::* StateFunc)();

	// 状態遷移関数
	void Update();

private:
	void Approach();
	void Shoot();
	void Leave();

	// 現在の状態
	int currentState_ = 0; // 0: Approach, 1: Shoot, 2: Leave

	// メンバ関数ポインタのテーブル
	static StateFunc spFuncTable_[];
};

void Enemy::Update() {
	// 現在の状態に応じた関数を呼び出す
	(this->*spFuncTable_[currentState_])();

	// 次の状態に遷移
	currentState_ = (currentState_ + 1) % 3; // 状態を接近→射撃→離脱→接近の順に循環
}

void Enemy::Approach() {
	printf("敵が接近\n");
}

void Enemy::Shoot() {
	printf("敵が射撃\n");
}

void Enemy::Leave() {
	printf("敵が離脱\n");
}

// メンバ関数ポインタのテーブル
Enemy::StateFunc Enemy::spFuncTable_[] = {
	&Enemy::Approach,
	&Enemy::Shoot,
	&Enemy::Leave
};

int main() {
	Enemy enemy;

	// 10回更新して状態遷移を確認
	for (int i = 0; i < 10; ++i) {
		enemy.Update();
		Sleep(1000); // 1秒待機
	}

	return 0;
}
