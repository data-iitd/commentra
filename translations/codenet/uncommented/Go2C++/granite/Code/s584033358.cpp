
#include <iostream>

int main() {
	int n, k;
	std::cin >> n >> k;

	if (k <= (n+n%2)/2) {
		std::cout << "YES" << std::endl;
	} else {
		std::cout << "NO" << std::endl;
	}
}
