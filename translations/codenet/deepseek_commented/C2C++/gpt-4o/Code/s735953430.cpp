#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

int main() {
    // Step 1: Reading Input
    int i_min, min;
    int X, N;
    std::cin >> X >> N;
    
    // If no values are excluded, print X and exit
    if (N == 0) {
        std::cout << X << std::endl;
        return 0;
    }
    
    // Step 2: Initializing Arrays
    std::vector<int> plus(256);
    std::vector<int> minus(256);
    for (int i = 0; i < 256; i++) {
        plus[i] = i;
        minus[i] = -i;
    }
    
    // Step 3: Marking Excluded Values
    for (int i = 0; i < N; i++) {
        int j;
        std::cin >> j;
        plus[j] = 0;
    }
    
    // Step 4: Finding the Nearest Non-Zero Value
    i_min = 0;
    min = 1000;
    for (int i = 255; i >= 0; i--) {
        if (plus[i] == 0 && i > 0) {
            continue;
        }
        int k = X - plus[i];
        if (k < 0) { k *= -1; }
        if (k <= min) {
            min = k;
            i_min = i;
        }
    }
    
    // Step 5: Outputting the Result
    std::cout << i_min << std::endl;
    
    return 0;
}

// <END-OF-CODE>
