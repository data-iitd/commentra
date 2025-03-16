#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;
	std::cout << std::replace(s.begin(), s.end(), "2017", "2018", -1) << std::endl;
}

