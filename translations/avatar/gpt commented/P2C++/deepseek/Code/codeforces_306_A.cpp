#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Calculate the quotient (q) and remainder (r) when n is divided by m
    int q = n / m;  // Number of items each group will get
    int r = n % m;  // Remaining items after equal distribution

    // Create a vector 'a' initialized with 'm' elements, each set to the quotient 'q'
    vector<int> a(m, q);

    // Distribute the remainder 'r' among the first 'r' groups
    for (int i = 0; i < r; i++) {
        a[i] += 1;  // Increment the count for the first 'r' groups by 1
    }

    // Print the final distribution of items in each group
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";  // Print each group's item count on the same line
    }

    return 0;
}

