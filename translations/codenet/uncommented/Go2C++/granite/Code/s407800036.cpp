
#include <iostream>

int main() {
	// Code for A - Between Two Integers
	int A, B, C;
	std::cin >> A >> B >> C;

	if (C >= A && C <= B) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
}
