
#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	cin >> a;
	string tmp = a;
	tmp.replace(tmp.begin(), tmp.end(), "1", "0");
	string b = tmp;
	b.replace(b.begin(), b.end(), "9", "1");
	string ans = b;
	ans.replace(ans.begin(), ans.end(), "0", "9");
	cout << ans << endl;
	return 0;
}

