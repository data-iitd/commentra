
#include <iostream>

int main() {
	int n;
	unsigned long long int m;
	std::cin >> n;
	m = n;
	n--;
	for (; n > 1; n--) {
		m *= n;
	}
	std::cout << m << std::endl;
	return 0;
}

