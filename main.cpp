#include <iostream>
#include <string>
#include <chrono>

int main() {
	// コピー
	std::string a(100000, 'a');

	auto startCopy = std::chrono::high_resolution_clock::now();
	std::string b = a; // コピー
	auto endCopy = std::chrono::high_resolution_clock::now();
	auto copyResult = std::chrono::duration_cast<std::chrono::microseconds>(endCopy - startCopy).count();

	// 移動
	auto startMove = std::chrono::high_resolution_clock::now();
	std::string c = std::move(a); // 移動
	auto endMove = std::chrono::high_resolution_clock::now();
	auto resultMove = std::chrono::duration_cast<std::chrono::microseconds>(endMove - startMove).count();

	// 結果を表示
	std::cout << "100,000文字を移動とコピーで比較しました。\n";
	std::cout << "コピー: " << copyResult << "μs\n";
	std::cout << "移動  : " << resultMove << "μs\n";

	return 0;
}
