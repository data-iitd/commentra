#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	cout << count(s.begin(), s.end(), 'A') + count(s.begin(), s.end(), 'B') + count(s.begin(), s.end(), 'C') << endl;
}

