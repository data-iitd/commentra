#include <iostream>
#include <string>

int main() {
	std::string str, tmp, p;
	int slen, plen;
	int i, flag;
	
	std::cin >> str >> p;
	
	tmp = str;
	str += tmp;
	
	slen = str.length();
	plen = p.length();
	
	flag = 0;
	for (i = 0; i < slen - plen; i++) {
		if (str.substr(i, plen) == p) flag = 1;
	}
	
	if (flag) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
	
	return 0;
}

