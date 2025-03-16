
#include <iostream>

int main() {

	int r, D, x;
	std::cin >> r >> D >> x;

	for (int i = 1; i <= 10; i++) {
		std::cout << r*x - D << std::endl;
		x = r*x - D;
	}

	return 0;
}
//END-OF-CODE