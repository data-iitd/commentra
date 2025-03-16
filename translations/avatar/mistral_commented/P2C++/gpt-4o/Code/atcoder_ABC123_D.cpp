#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read input: four integers x, y, z, and k
    int x, y, z, k;
    std::cin >> x >> y >> z >> k;

    // Initialize vectors to store lists a, b, and c
    std::vector<int> a(x), b(y), c(z);

    // Read the elements of list a
    for (int i = 0; i < x; ++i) {
        std::cin >> a[i];
    }

    // Read the elements of list b
    for (int i = 0; i < y; ++i) {
        std::cin >> b[i];
    }

    // Read the elements of list c
    for (int i = 0; i < z; ++i) {
        std::cin >> c[i];
    }

    // Initialize a vector ab to store the sum of each element from list a with each element from list b
    std::vector<int> ab;

    // Iterate through each element in list a and b, appending their sum to list ab
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            ab.push_back(a[i] + b[j]);
        }
    }

    // Sort list ab in descending order
    std::sort(ab.rbegin(), ab.rend());

    // Initialize a vector abc to store the sum of each element from list ab with each element from list c
    std::vector<int> abc;

    // Iterate through each valid index i in the range of min(k, x * y), and for each index j in the range of z
    for (int i = 0; i < std::min(k, static_cast<int>(ab.size())); ++i) {
        for (int j = 0; j < z; ++j) {
            abc.push_back(ab[i] + c[j]);
        }
    }

    // Sort list abc in descending order
    std::sort(abc.rbegin(), abc.rend());

    // Iterate through the first k elements of list abc and print each element
    for (int i = 0; i < k; ++i) {
        std::cout << abc[i] << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
