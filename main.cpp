#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

struct KmtMail {
	std::string email;
	int year;
	int number;
};

// メールアドレスから年度と学籍番号を出す
static KmtMail ParseEmail(const std::string& email) {
	const std::regex pattern(R"(k(\d{3})g(\d{4})@)");
	std::smatch match;
	if (std::regex_search(email, match, pattern)) {
		const int year = std::stoi(match[1].str());
		const int number = std::stoi(match[2].str());
		return {email, year, number};
	}
	return {email, -1, -1}; // 失敗
}

int main() {
	// ファイルを開く
	std::ifstream file("PG3_2024_03_02.txt");
	if (!file) {
		std::cerr << "ファイルを開けませんでした。\n";
		return 1;
	}

	std::string line;
	std::vector<KmtMail> emails;

	// ファイルからメールアドレスを読む
	while (std::getline(file, line)) {
		// 配列からメールアドレスを抽出
		std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
		auto begin = std::sregex_iterator(line.begin(), line.end(), emailPattern);
		auto end = std::sregex_iterator();

		for (auto it = begin; it != end; ++it) {
			KmtMail info = ParseEmail(it->str());
			if (info.year != -1 && info.number != -1) {
				emails.push_back(info);
			}
		}
	}

	// 年と番号でソート
	std::sort(emails.begin(), emails.end(), [](const KmtMail& a, const KmtMail& b) {
		if (a.year != b.year) {
			return a.year < b.year;
		}
		return a.number < b.number;
	});

	// プリント
	for (const auto& email : emails) {
		std::cout << email.email << '\n';
	}

	return 0;
}
