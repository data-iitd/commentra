#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int x, y, z, k;
    std::cin >> x >> y >> z >> k;

    std::vector<int> a(x);
    for (int i = 0; i < x; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> b(y);
    for (int i = 0; i < y; ++i) {
        std::cin >> b[i];
    }

    std::vector<int> c(z);
    for (int i = 0; i < z; ++i) {
        std::cin >> c[i];
    }

    // Initialize an empty vector to store the sums of elements from lists a and b
    std::vector<int> ab;

    // Calculate all possible sums of elements from list a and list b
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            ab.push_back(a[i] + b[j]);
        }
    }

    // Sort the list of sums in descending order
    std::sort(ab.begin(), ab.end(), std::greater<int>());

    // Initialize an empty vector to store the sums of the top k elements from ab and elements from list c
    std::vector<int> abc;

    // Calculate sums of the top k elements from ab with each element in c
    for (int i = 0; i < std::min(k, static_cast<int>(ab.size())); ++i) {
        for (int j = 0; j < z; ++j) {
            abc.push_back(ab[i] + c[j]);
        }
    }

    // Sort the resulting sums in descending order
    std::sort(abc.begin(), abc.end(), std::greater<int>());

    // Print the top k sums from the final list abc
    for (int i = 0; i < k; ++i) {
        std::cout << abc[i] << std::endl;
    }

    return 0;
}
