
#include <iostream>
#include <string>

int main() {
	int n;
	std::string s;
	std::cin >> n >> s;
	std::cout << std::count(s.begin(), s.end(), "ABC") << std::endl;
}
