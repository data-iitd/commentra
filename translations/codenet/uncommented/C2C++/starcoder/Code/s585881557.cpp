#include <iostream>

using namespace std;

int main(void) {
	int h,r;
	cin >> h >> r;
	if(r > -h){cout << "1\n";}
	else if (r == -h){cout << "0\n";}
	else{cout << "-1\n";}
	return 0;
}

