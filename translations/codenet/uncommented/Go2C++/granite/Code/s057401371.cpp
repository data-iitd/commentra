
#include <iostream>
#include <cstdio>

int main() {
	std::string s;
	std::cin >> s;

	int d = 'a' - 'A';
	for (char &r : s) {
		char rr = r;
		if ('A' <= r && r <= 'Z') {
			rr = r + d;
		} else if ('a' <= r && r <= 'z') {
			rr = r - d;
		}
		std::printf("%c", rr);
	}
	std::printf("\n");
}

