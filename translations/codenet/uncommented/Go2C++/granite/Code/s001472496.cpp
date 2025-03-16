
#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;

	int max_tmp = 0;
	int max = 0;
	for (int i = 0; i < s.length(); i++) {
		bool flag = false;
		switch (s[i]) {
		case 'A':
		case 'C':
		case 'T':
		case 'G':
			max_tmp++;
			break;
		default:
			flag = true;
			break;
		}

		if (i == s.length() - 1) {
			flag = true;
		}
		if (flag == true) {
			if (max < max_tmp) {
				max = max_tmp;
			}
			max_tmp = 0;
		}
	}
	std::cout << max << std::endl;
}

