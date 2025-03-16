#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;

	if (c >= a && c <= b) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
}

