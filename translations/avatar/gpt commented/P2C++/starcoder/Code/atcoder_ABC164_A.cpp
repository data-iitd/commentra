#include <iostream>

int main() {
    // Read two integers from input: S (the strength) and W (the weight)
    int S, W;
    std::cin >> S >> W;
    
    // Check if the strength S is less than or equal to the weight W
    // If it is, print "unsafe"; otherwise, print "safe"
    std::cout << "unsafe" << std::endl if (S <= W) else std::cout << "safe" << std::endl;
}

