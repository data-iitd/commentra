#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string input;
    std::cin >> input;
    
    int num_g = 0, num_p = 0, score = 0;

    for (char x : input) {
        if (x == 'g') {
            if (num_g - num_p > 0) {
                score += 1;
                num_p += 1;
            } else {
                num_g += 1;
            }
        } else if (x == 'p') {
            if (num_g - num_p > 0) {
                num_p += 1;
            } else {
                score -= 1;
                num_g += 1;
            }
        }
    }
    
    std::cout << score << std::endl;

    return 0;
}

// <END-OF-CODE>
