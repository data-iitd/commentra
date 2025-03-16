
#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;
	if (s.length() >= 4 && s.substr(0, 4) == "YAKI") {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
}
