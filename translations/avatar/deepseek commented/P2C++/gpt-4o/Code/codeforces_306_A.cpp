#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;  // Take two integers n and m as input

    int q = n / m;  // Calculate the quotient
    int r = n % m;  // Calculate the remainder

    std::vector<int> a(m, q);  // Initialize a vector a of length m with each element set to q

    for (int i = 0; i < r; ++i) {  // Loop for the number of remaining items r
        a[i] += 1;  // Increment the corresponding element in the vector a by 1
    }

    for (int i = 0; i < m; ++i) {  // Loop to print the elements of the vector a
        std::cout << a[i] << ' ';  // Print each element separated by a space
    }

    return 0;
}

// <END-OF-CODE>
