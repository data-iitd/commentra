#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int L, tmp, d, def, end, aj, max, min;

    while (true) {
        std::vector<int> an(20), a1(6), a2(6);
        std::cin >> an[0] >> L;
        if (L == 0) break; // If L is 0, break out of the loop

        aj = an[0];
        end = 0;
        for (int k = 1; k < 21; k++) {
            for (int i = L - 1; i >= 0; i--, aj /= 10) {
                a1[i] = aj % 10; 
                a2[i] = aj % 10; // Initialize a1 and a2 with the digits of aj
            }
            for (int i = 1; i < L; i++) {
                for (int j = 1; j < L; j++) {
                    if (a1[j - 1] < a1[j]) { // Sort a1 in ascending order
                        std::swap(a1[j - 1], a1[j]);
                    }
                    if (a2[j - 1] > a2[j]) { // Sort a2 in descending order
                        std::swap(a2[j - 1], a2[j]);
                    }
                }
            }
            d = 1; 
            max = 0; 
            min = 0;
            for (int i = L - 1; i >= 0; i--, d *= 10) {
                max += (a1[i] % 10) * d; // Calculate max by combining sorted digits
                min += (a2[i] % 10) * d; // Calculate min by combining sorted digits
            }
            def = max - min; // Calculate the difference def
            for (int i = 0; i < k; i++) {
                if (def == an[i]) { // Check if def has been seen before
                    std::cout << i << " " << def << " " << k - i << std::endl; // Print the index, def, and steps taken
                    end = 1; 
                    break; // Set end to 1 to break out of the loop
                }
            }
            if (end == 1) break; // If end is 1, break out of the loop
            an[k] = def; 
            aj = def; // Add def to an and update aj
        }
    }

    return 0;
}

// <END-OF-CODE>
