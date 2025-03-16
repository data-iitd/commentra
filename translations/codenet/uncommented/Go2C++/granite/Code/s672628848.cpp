
#include <iostream>

int main() {
	int a, b, c, d, e;

	std::cin >> a >> b >> c >> d >> e;

	int al[] = {a, b, c, d, e};

	for (int n = 0; n < 5; n++) {
		if (al[n] == 0) {
			std::cout << n + 1 << std::endl;
			break;
		}
	}

	return 0;
}

