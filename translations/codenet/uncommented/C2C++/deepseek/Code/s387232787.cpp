#include <iostream>
#include <string>

int c[26];

int main()
{
	std::string str;
	while (std::cin >> str) {
		for (char &ch : str) {
			if ('a' <= ch && ch <= 'z') {
				c[ch - 'a']++;
			} else if ('A' <= ch && ch <= 'Z') {
				c[ch - 'A']++;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		std::cout << char('a' + i) << " : " << c[i] << std::endl;
	}
	return 0;
}

