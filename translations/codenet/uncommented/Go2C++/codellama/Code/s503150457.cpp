#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	vector<string> s1s = split(s1);
	vector<string> s2s = split(s2);
	vector<string> s3s = split(s3);

	cout << toUpper(s1s[0]) + toUpper(s2s[0]) + toUpper(s3s[0]) << endl;

	return 0;
}

string toUpper(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = s[i] - 32;
		}
	}
	return s;
}

vector<string> split(string s) {
	vector<string> v;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			v.push_back(s.substr(0, i));
			s = s.substr(i + 1);
			i = -1;
		}
	}
	v.push_back(s);
	return v;
}

