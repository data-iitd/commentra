
#include <iostream>
#include <string>

int main() {
	int n;
	std::string s;
	
	std::cin >> n;
	std::cin >> s;
	
	int count = 0;
	for (int i = 0; i < s.length() - 2; i++) {
		if (s.substr(i, 3) == "ABC") {
			count++;
		}
	}
	
	std::cout << count << std::endl;
	
	return 0;
}

