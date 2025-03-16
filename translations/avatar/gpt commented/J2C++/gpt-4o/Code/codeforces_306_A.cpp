#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read two integers n and m from user input
    int n, m;
    cin >> n >> m;

    // Initialize a vector of size m to hold the results
    vector<int> a(m);

    // Check if n is divisible by m
    if (n % m == 0) {
        // If divisible, fill the vector with equal parts
        for (int i = 0; i < a.size(); i++) {
            a[i] = n / m;
        }
    } else {
        // If not divisible, calculate the base value for each part
        int sub = n / m;
        for (int i = 0; i < a.size(); i++) {
            a[i] = sub;
        }

        // Calculate the remainder that needs to be distributed
        int test = n - (sub * m);
        int count = 0;

        // Distribute the remainder across the first few elements of the vector
        for (int i = 0; i < test; i++) {
            a[count] = a[count] + 1;
            count++;

            // Wrap around if count exceeds the vector length
            if (count >= a.size()) count = 0;
        }
    }

    // Print the vector in reverse order
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }

    return 0;
}

// <END-OF-CODE>
