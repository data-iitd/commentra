#include <iostream>

int main() {
	int n, k, cnt;

	std::cin >> n >> k;
	cnt = 0;
	while (n--) {
		int h;

		std::cin >> h;
		if (h >= k)
			cnt++;
	}
	std::cout << cnt << std::endl;
	return 0;
}

