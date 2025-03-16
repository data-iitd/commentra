
#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s.substr(i + 1).find(s[i])!= std::string::npos) {
			std::cout << "no" << std::endl;
			return 0;
		}
	}

	std::cout << "yes" << std::endl;

	return 0;
}

