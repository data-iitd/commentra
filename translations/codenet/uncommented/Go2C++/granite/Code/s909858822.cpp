
#include <iostream>

int main() {
	int A, B;
	std::cin >> A >> B;

	int ans = 0;
	if (6 <= A && A <= 12) {
		ans = B / 2;
	} else if (12 < A) {
		ans = B;
	}
	std::cout << ans << std::endl;
}

