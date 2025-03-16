
#include <iostream>
#include <string>

int main() {
	int n;
	std::string s;
	std::cin >> n;
	std::cin >> s;
	std::cout << std::count(s.begin(), s.end(), "ABC") << std::endl;
}
