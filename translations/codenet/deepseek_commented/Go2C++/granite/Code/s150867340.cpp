
#include <iostream> // Importing the iostream library for input/output operations

int main() {
	int a, b; // Declaring two integer variables `a` and `b`
	std::cin >> a >> b; // Reading two integers from the standard input
	if (auto product = a * b; product % 2 == 0) { // Calculating the product and checking if it's even
		std::cout << "Even" << std::endl; // Printing "Even" if the product is even
	} else {
		std::cout << "Odd" << std::endl; // Printing "Odd" if the product is odd
	}
	return 0;
}

