#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <functional> 

void SetTimeout(const std::function<void(int*)>& p, const int second, int* result) {
	Sleep(second * 1000);
	p(result);
}

int main() {
	printf("奇数か偶数か入力してください\n奇数 = 0, 偶数 = 1\n");

	int answer;
	scanf_s("%d", &answer);

	srand(static_cast<unsigned int>(time(nullptr)));
	int randomResult = rand() % 2;

	auto DispResult = [answer](const int* result) {
		if (*result == answer) {
			printf("正解!\n");
		} else {
			printf("不正解...\n");
		}
		};

	printf("答えは...\n");
	SetTimeout(DispResult, 3, &randomResult);

	return 0;
}
