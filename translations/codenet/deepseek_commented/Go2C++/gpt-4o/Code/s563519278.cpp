#include <iostream>
#include <vector>

int main() {
    int N; // Step 1: Reading the number of elements (N)
    std::cin >> N;
    std::vector<int> v(N, 0); // Step 3: Initializing the array

    int a;
    for (int i = 0; i < N; i++) { // Step 4: Reading and counting elements
        std::cin >> a;
        v[a - 1]++;
    }

    for (const auto& e : v) { // Step 5: Writing the results
        std::cout << e << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
