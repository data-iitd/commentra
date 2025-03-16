#include <iostream>

int main() {
	int N = 0;
	int R = 0;

	std::cin >> N >> R;

	if(N >= 10) {
		std::cout << R << std::endl;
	} else {
		std::cout << R + 100*(10-N) << std::endl;
	}

	return 0;
}

