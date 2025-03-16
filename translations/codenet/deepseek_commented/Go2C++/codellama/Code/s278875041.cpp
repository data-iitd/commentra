
#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	cin >> a;
	string tmp = a;
	tmp.replace(0, tmp.length(), "0");
	string b = tmp;
	b.replace(0, b.length(), "1");
	string ans = b;
	ans.replace(0, ans.length(), "9");
	cout << ans << endl;
	return 0;
}

