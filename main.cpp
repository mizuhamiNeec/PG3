#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>

typedef void(*PFunc)(int*);

void DispResult(int* result) {
	if (*result == 0) {
		printf("正解!\n");
	} else {
		printf("不正解...\n");
	}
}

void SetTimeout(PFunc p, int second, int* result) {
	Sleep(second * 1000);
	p(result);
}

int main() {
	printf("奇数か偶数か入力してください\n奇数 = 0, 偶数 = 1\n");

	int answer;
	scanf_s("%d", &answer);

	// ランダムな結果を生成
	srand(static_cast<unsigned int>(time(NULL)));
	int randomResult = rand() % 2;

	PFunc p;
	p = DispResult;

	printf("答えは...\n");
	SetTimeout(p, 3, &randomResult);  // 3秒後に結果を表示

	return 0;
}