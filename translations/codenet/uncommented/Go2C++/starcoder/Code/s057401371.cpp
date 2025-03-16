#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;

	for (auto r : s) {
		char rr = r;
		if ('A' <= r && r <= 'Z') {
			rr = r + ('a' - 'A');
		} else if ('a' <= r && r <= 'z') {
			rr = r - ('a' - 'A');
		}
		std::cout << rr;
	}
	std::cout << std::endl;
}

