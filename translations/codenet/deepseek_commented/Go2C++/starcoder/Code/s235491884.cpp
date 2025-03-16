#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int n = count(s.begin(), s.end(), 'o');
	cout << 700 + n * 100 << endl;
}

