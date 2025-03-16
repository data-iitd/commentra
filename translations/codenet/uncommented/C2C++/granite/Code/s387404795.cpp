
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str, tmp, p;
	int slen, plen;
	int i, j, flag;
	
	cin >> str >> p;
	
	tmp = str;
	str += tmp;
	
	slen = str.length();
	plen = p.length();
	
	flag = 0;
	for (i = 0; i < slen - plen; i++) {
		if (str.substr(i, plen) == p) flag = 1;
	}
	
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
