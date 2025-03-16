
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> b;
	for (const auto &v : a) {
		auto x = std::lower_bound(b.begin(), b.end(), v);
		if (x == b.end()) {
			b.push_back(v);
		} else {
			*x = v;
		}
	}

	std::cout << b.size() << std::endl;
}


Translate the above C++ code to Rust and end with comment "