

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // Take two integers n and m as input

    int q = n / m;  // Calculate the quotient, which is the number of items each group will have
    int r = n % m;   // Calculate the remainder, which is the number of items that will be left over

    vector<int> a(m, q);  // Initialize a vector a of length m with each element set to q
    // This represents the initial distribution of items among the groups

    for (int i = 0; i < r; i++) {  // Loop for the number of remaining items r
        a[i]++;  // Increment the corresponding element in the vector a by 1
        // Ensuring that the remaining items are distributed evenly
    }

    for (int i = 0; i < m; i++) {  // Loop to print the elements of the vector a
        cout << a[i] << " ";  // Print each element separated by a space
    }

    return 0;
}

