#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	cin >> a;
	string tmp = a.replace(0, a.length(), "0", "1");
	string b = tmp.replace(0, tmp.length(), "9", "1");
	string ans = b.replace(0, b.length(), "0", "9");
	cout << ans << endl;
	return 0;
}

