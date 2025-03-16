
#include <iostream>
#include <string>

int main() {
	std::string s1,s2,s3;
	std::cin >> s1 >> s2 >> s3;

	std::string s1s = s1;
	std::string s2s = s2;
	std::string s3s = s3;

	std::cout << std::toupper(s1s[0]) << std::toupper(s2s[0]) << std::toupper(s3s[0]) << std::endl;
}

