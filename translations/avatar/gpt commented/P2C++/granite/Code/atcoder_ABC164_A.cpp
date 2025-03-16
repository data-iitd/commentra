
#include <iostream>

int main() {
    // Read two integers from input: S (the strength) and W (the weight)
    int S, W;
    std::cin >> S >> W;
    
    // Check if the strength S is less than or equal to the weight W
    // If it is, print "unsafe"; otherwise, print "safe"
    if (S <= W) {
        std::cout << "unsafe" << std::endl;
    } else {
        std::cout << "safe" << std::endl;
    }
    
    return 0;
}

// Entry point of the program
