#include <iostream>

int main(void) {
	int h,r;
	std::cin >> h >> r;
	if(r > -h){std::cout << "1\n";}
	else if (r == -h){std::cout << "0\n";}
	else{std::cout << "-1\n";}
	return 0;
}

