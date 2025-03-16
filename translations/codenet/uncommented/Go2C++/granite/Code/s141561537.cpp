
#include <iostream>

int main() {
	int a, b, c, x, sum = 0;
	std::cin >> a >> b >> c >> x;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				if (500*i+100*j+50*k == x) {
					sum++;
				}
			}
		}
	}
	std::cout << sum << std::endl;
	return 0;
}
