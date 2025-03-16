#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, tmp, p;
	int slen, plen;
	int i, j, flag;
	
	// Read two strings from the user
	cin >> str >> p;
	
	// Duplicate and concatenate the string
	tmp = str;
	str += tmp;
	
	// Calculate the lengths of the strings
	slen = str.length();
	plen = p.length();
	
	// Initialize flag to 0 (not found)
	flag = 0;
	
	// Check if the pattern exists in the concatenated string
	for (i = 0; i < slen - plen; i++) {
		if (str.substr(i, plen) == p) flag = 1;
	}
	
	// Output the result
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}

