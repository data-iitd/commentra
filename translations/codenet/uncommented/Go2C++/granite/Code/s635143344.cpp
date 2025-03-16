
#include <iostream>
#include <algorithm>

int main() {
	int in[3];
	std::cin >> in[0] >> in[1] >> in[2];
	std::sort(in, in + 3);

	std::cout << in[2]*10 + in[1] + in[0] << std::endl;
}

