
#include <iostream>
#include <cctype>

int main() {
	std::string s;
	std::cin >> s;
	int l = s.length();
	std::string ans = "AC";
	if (s[0]!= 'A') {
		ans = "WA";
	}
	int cnt = 0;
	for (int i = 1; i < l; i++) {
		if (std::isupper(s[i])) {
			if (i == 1 || i == l - 1 || s[i]!= 'C') {
				ans = "WA";
			}
			cnt++;
		}
	}
	if (cnt!= 1) {
		ans = "WA";
	}
	std::cout << ans << std::endl;
}

