#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the values of n and m from the user
    int n, m;
    cin >> n >> m;

    // Initialize a vector of size m
    vector<int> a(m);

    // Check if n is divisible by m
    if (n % m == 0) {
        // Fill the vector with equal parts if n is divisible by m
        for (int i = 0; i < a.size(); i++) {
            a[i] = n / m;
        }
    } else {
        // Calculate the base part size
        int sub = n / m;

        // Fill the vector with the base part size
        for (int i = 0; i < a.size(); i++) {
            a[i] = sub;
        }

        // Distribute the remainder
        int test = n - (sub * m);
        int count = 0;
        for (int i = 0; i < test; i++) {
            a[count] = a[count] + 1;
            count++;
            if (count >= a.size()) count = 0;
        }
    }

    // Print the vector elements in reverse order
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }

    return 0;
}

// <END-OF-CODE>
