
#include <iostream>

int main() {
	int K, X;
	std::cin >> K >> X;
	if (500*K >= X) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
	return 0;
}
// END-OF-CODE