#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

// 駅リストを表示する関数
static void PrintStationList(const std::list<const char*>& stationList) {
	for (const auto& station : stationList) {
		std::cout << station << " -> ";
	}
	std::cout << "Loop\n";
}

int main() {
	// 山手線の駅リスト（1970年時点）
	std::list<const char*> stationList1970 = {
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
		"Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo",
		"Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
		"Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
		"Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi",
		"Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	// 表示：1970年
	std::cout << "1970:\n";
	PrintStationList(stationList1970);

	// 1971年：西日暮里駅を追加
	std::list<const char*> stationList2019 = stationList1970;
	auto it = std::find(stationList2019.begin(), stationList2019.end(), "Nippori");
	if (it != stationList2019.end()) {
		stationList2019.insert(it, "Nishi-Nippori");
	}

	// 表示：2019年（西日暮里駅のみ追加）
	std::cout << "\n2019:\n";
	PrintStationList(stationList2019);

	// 2020年：高輪ゲートウェイ駅を追加
	std::list<const char*> stationList2022 = stationList2019;
	it = std::find(stationList2022.begin(), stationList2022.end(), "Tamachi");
	if (it != stationList2022.end()) {
		stationList2022.insert(std::next(it), "Takanawa Gateway");
	}

	// 表示：2022年（西日暮里駅と高輪ゲートウェイ駅を含む）
	std::cout << "\n2022:\n";
	PrintStationList(stationList2022);

	return 0;
}