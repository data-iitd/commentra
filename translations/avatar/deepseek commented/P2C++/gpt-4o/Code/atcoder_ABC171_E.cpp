#include <iostream>
#include <vector>
#include <numeric>
#include <sstream>

int main() {
    // Step 1: Take an integer input N, which represents the number of elements in the list.
    int N;
    std::cin >> N;

    // Step 2: Take a list of integers as input and store them in the vector 'a'.
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    // Step 3: Calculate the total XOR of all elements in the vector 'a'.
    int total = 0;
    for (int num : a) {
        total ^= num;
    }

    // Step 4: Create a new list where each element is the XOR of the original element and the total.
    std::ostringstream result;
    for (int num : a) {
        result << (num ^ total) << " ";
    }

    // Print the new list as a space-separated string.
    std::cout << result.str() << std::endl;

    return 0;
}

// <END-OF-CODE>
