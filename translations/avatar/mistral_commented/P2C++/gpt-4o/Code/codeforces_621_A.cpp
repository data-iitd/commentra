#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Take an integer 'n' as input
    int n;
    std::cin >> n;

    // Create a vector 'lst' of 'n' integers taken as input
    std::vector<int> lst(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> lst[i];
    }

    // Sort the vector 'lst' in ascending order
    std::sort(lst.begin(), lst.end());

    // Reverse the sorted vector 'lst'
    std::reverse(lst.begin(), lst.end());

    // Initialize odd_digits counter 'od' to 0
    int od = 0;

    // Iterate through each integer 'i' in the vector 'lst'
    for (int i = 0; i < n; ++i) {
        // If the integer 'i' has an odd number of bits (1 in binary representation), increment 'od' counter
        if (lst[i] & 1) {
            od++;
        }
    }

    // Initialize sum and ok variables
    int sum = 0;
    bool ok = false;

    // Iterate through each index 'i' in the range of 'n'
    for (int i = 0; i < n; ++i) {
        // If the integer at index 'i' in the vector 'lst' is even, add it to the sum 'sum'
        if (lst[i] % 2 == 0) {
            sum += lst[i];
        } 
        // If the integer at index 'i' in the vector 'lst' is odd and either 'ok' is true or 'od' is greater than 1
        else {
            if (ok || od > 1) {
                sum += lst[i];
                od--;
                ok = !ok;
            }
        }
    }

    // Print the final sum
    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
