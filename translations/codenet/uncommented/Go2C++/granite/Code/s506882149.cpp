
#include <iostream>

int comp(int x, int a) {
	if (x < a) {
		return 0;
	}
	return 10;
}

int main() {
	int x, a;
	std::cin >> x >> a;

	std::cout << comp(x, a) << std::endl;

	return 0;
}

