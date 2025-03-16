
#include <iostream>
#include <string>

int main() {
	std::string a;
	std::cin >> a;
	std::string tmp = std::string(a.length(), '0');
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '1') {
			tmp[i] = '0';
		}
	}
	std::string b = std::string(a.length(), '0');
	for (int i = 0; i < a.length(); i++) {
		if (tmp[i] == '9') {
			b[i] = '1';
		}
	}
	std::string ans = std::string(a.length(), '0');
	for (int i = 0; i < a.length(); i++) {
		if (b[i] == '0') {
			ans[i] = '9';
		}
	}
	std::cout << ans << std::endl;
	return 0;
}

