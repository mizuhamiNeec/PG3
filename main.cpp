#include <cstdio>
#include <Windows.h>

// クラステンプレート
template <typename T1, typename T2>
class MinComparer {
public:
	// コンストラクタ
	MinComparer(T1 val1, T2 val2) : m_val1(val1), m_val2(val2) {}

	// 2つの引数を比較して小さい方をT1型で返すメンバ関数
	T1 Min() const {
		if (m_val1 < m_val2) {
			return static_cast<T1>(m_val1);
		}
		return static_cast<T1>(m_val2);
	}

private:
	T1 m_val1;
	T2 m_val2;
};

int main() {
	// int と float の比較
	MinComparer<int, float> comparer1(5, 3.5f);
	printf("Smallest value (int, float): %d\n", comparer1.Min());

	// int と double の比較
	MinComparer<int, double> comparer2(5, 6.7);
	printf("Smallest value (int, double): %d\n", comparer2.Min());

	// float と int の比較
	MinComparer<float, int> comparer3(3.7f, 6);
	printf("Smallest value (float, int): %f\n", comparer3.Min());

	// float と double の比較
	MinComparer<float, double> comparer4(3.7f, 2.9);
	printf("Smallest value (float, double): %f\n", comparer4.Min());

	// double と int の比較
	MinComparer<double, int> comparer5(4.5, 7);
	printf("Smallest value (double, int): %f\n", comparer5.Min());

	// double と float の比較
	MinComparer<double, float> comparer6(5.6, 4.3f);
	printf("Smallest value (double, float): %f\n", comparer6.Min());

	return 0;
}
