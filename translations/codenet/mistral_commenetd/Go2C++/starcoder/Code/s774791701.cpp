#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;

	int price = 700;

	for (auto c : s) {
		if (c == 'o') {
			price += 100;
		}
	}

	std::cout << price << std::endl;
}

