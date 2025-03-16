
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    int q = n / m;  // Number of items each group will get
    int r = n % m;   // Remaining items after equal distribution

    std::vector<int> a(m, q);  // Create a vector 'a' initialized with'm' elements, each set to the quotient 'q'

    for (int i = 0; i < r; i++) {
        a[i]++;  // Increment the count for the first 'r' groups by 1
    }

    for (int i = 0; i < m; i++) {
        std::cout << a[i] << " ";  // Print each group's item count on the same line
    }

    return 0;
}
