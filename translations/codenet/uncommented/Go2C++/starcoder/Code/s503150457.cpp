#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;

	string s1s[s1.size()+1];
	string s2s[s2.size()+1];
	string s3s[s3.size()+1];

	for (int i = 0; i < s1.size(); i++) {
		s1s[i] = s1[i];
	}
	for (int i = 0; i < s2.size(); i++) {
		s2s[i] = s2[i];
	}
	for (int i = 0; i < s3.size(); i++) {
		s3s[i] = s3[i];
	}

	cout << s1s[0] << s2s[0] << s3s[0] << endl;
}

