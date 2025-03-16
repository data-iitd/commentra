#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	cout << count(s.begin(), s.end(), "ABC") << endl;
}

