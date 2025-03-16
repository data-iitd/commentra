#include <iostream>
#include <vector>

using namespace std;

int substract(int a, int b) {
    // Check if a is greater than b
    if (a > b) {
        int total = 0;  // Initialize the total count of subtractions
        // Loop to subtract b from a until one of them becomes zero
        while (a > 0 && b > 0) {
            total += a / b;  // Count how many times b can be subtracted from a
            a = a % b;  // Update a to the remainder of a divided by b
            if (a > 0) {
                total += b / a;  // Count how many times a can be subtracted from b
                b = b % a;  // Update b to the remainder of b divided by a
            }
        }
        return total;  // Return the total count of subtractions
    }

    // If a is less than b, perform similar operations but subtract a from b
    if (a < b) {
        int total = 0;  // Initialize the total count of subtractions
        while (a > 0 && b > 0) {
            total += b / a;  // Count how many times a can be subtracted from b
            b = b % a;  // Update b to the remainder of b divided by a
            if (b > 0) {
                total += a / b;  // Count how many times b can be subtracted from a
                a = a % b;  // Update a to the remainder of a divided by b
            }
        }
        return total;  // Return the total count of subtractions
    }

    // If a and b are equal, return 1
    if (a == b) {
        return 1;
    }

    return 0; // In case of unexpected input, return 0
}

int main() {
    int n;
    cin >> n;  // Read the number of pairs of integers
    vector<int> lst;  // Initialize a vector to store the results

    // Read n pairs of integers and compute the result using the substract function
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lst.push_back(substract(a, b));
    }

    // Print each element in the vector
    for (int i : lst) {
        cout << i << endl;
    }

    return 0;
}

// <END-OF-CODE>
