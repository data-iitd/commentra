#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	cout << count(s.begin(), s.end(), 'A') << endl;
	return 0;
}

