#include <iostream>

int main() {
	int a, b;
	std::cin >> a >> b;
	if (int product = a * b; product%2 == 0) {
		std::cout << "Even" << std::endl;
	} else {
		std::cout << "Odd" << std::endl;
	}
}

