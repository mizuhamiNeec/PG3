#include <cstdio>
#include <valarray>

int Recursive(const int pay, const int hour) {
	if (hour == 1) {
		return pay;
	}
	const int current = pay * 2 - 50;
	return pay + Recursive(current, hour - 1);
}

int main() {
	printf("何時間働かせますか?\n");

	int workTime;
	scanf_s("%d", &workTime);

	workTime = std::abs(workTime);

	printf("%d時間働きます...\n", workTime);

	// 一般的な資金体系 時給1072円
	int pay = 0;

	for (unsigned int i = 0; i < workTime; ++i) {
		pay += 1072;
	}

	printf("一般的 : %d\n", pay);

	// 再帰的な資金体系
	constexpr int start = 100;
	const int result = Recursive(start, workTime); // 計算結果 
	printf("再帰的 : %d\n", result);

	return 0;
}
