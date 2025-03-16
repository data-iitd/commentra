
#include <iostream>
#include <string>

int main() {
	std::string n;
	std::cin >> n;
	
	for (int i = 0; i < 3; i++) {
		if (n[i] == '7') {
			std::cout << "Yes" << std::endl;
			return 0;
		}
	}
	std::cout << "No" << std::endl;
}
