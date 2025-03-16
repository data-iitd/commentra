#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int x, y, z, k;
    std::cin >> x >> y >> z >> k;
    // Taking four integer inputs: x, y, z, and k

    std::vector<int> a(x), b(y), c(z);
    for (int i = 0; i < x; ++i) {
        std::cin >> a[i];
    }
    // Reading list a of integers

    for (int i = 0; i < y; ++i) {
        std::cin >> b[i];
    }
    // Reading list b of integers

    for (int i = 0; i < z; ++i) {
        std::cin >> c[i];
    }
    // Reading list c of integers

    std::vector<int> ab;
    // Initializing an empty vector ab to store sums of elements from a and b

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            ab.push_back(a[i] + b[j]);
        }
    }
    // Populating vector ab with sums of elements from a and b

    std::sort(ab.rbegin(), ab.rend());
    // Sorting vector ab in descending order

    std::vector<int> abc;
    // Initializing an empty vector abc to store sums of elements from ab and c

    for (int i = 0; i < std::min(k, x * y); ++i) {
        for (int j = 0; j < z; ++j) {
            abc.push_back(ab[i] + c[j]);
        }
    }
    // Populating vector abc with sums of elements from ab and c, limited by k

    std::sort(abc.rbegin(), abc.rend());
    // Sorting vector abc in descending order

    for (int i = 0; i < k; ++i) {
        std::cout << abc[i] << std::endl;
    }
    // Printing the first k elements of abc in descending order

    return 0;
}
// <END-OF-CODE>
