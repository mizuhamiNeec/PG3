#include <cstdio>

template <typename T>
T Min(T a, T b) {
	if (a < b) { return a; }
	if (b < a) { return b; }
	return 0;
}

template <>
char Min<char>(char a, char b) {
	printf("数字以外は代入できません。");
	return 0;
}

int main() {

	printf("%d\n", Min<int>(114, 514));
	printf("%f\n", Min<float>(114.0f, 514.0f));
	printf("%lf\n", Min<double>(114.0, 514.0));
	printf("%c\n", Min<char>('a', 'b'));

	return 0;
}
