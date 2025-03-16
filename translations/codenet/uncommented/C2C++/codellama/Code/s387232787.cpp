#include <iostream>

int c[26];

int main(void)
{
	char str[1200];
	for (; std::cin >> str;) {
		for (char *p = str; *p; p++) {
			if ('a' <= *p && *p <= 'z') {
				c[*p - 'a']++;
			} else if ('A' <= *p && *p <= 'Z') {
				c[*p - 'A']++;
			}

		}
	}
	for (int i = 0; i < 26; i++) {
		std::cout << char('a' + i) << " : " << c[i] << std::endl; 
	}
	return 0;
}

