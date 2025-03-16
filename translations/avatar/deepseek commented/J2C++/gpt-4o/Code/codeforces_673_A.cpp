#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements in the list `a`
    vector<int> a; // Create a vector to store the integers

    int value;
    for (int i = 0; i < n; i++) {
        cin >> value; // Read each integer value
        a.push_back(value); // Add the value to the vector `a`
    }

    int result, pos = 0, flag = 0;

    if (a[0] > 15) {
        result = 15; // If the first element is greater than 15, set result to 15
    } else {
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] > 15) {
                pos = i - 1; // Find the position where the difference is greater than 15
                flag = 1; // Set flag to 1 indicating such a position is found
                break;
            }
        }
        if (flag == 1) {
            result = a[pos] + 15; // Set result to the element at pos plus 15
        } else {
            result = a[n - 1] + 15; // Otherwise, set result to the last element plus 15
        }
    }

    if (result > 90) {
        result = 90; // If result is greater than 90, set it to 90
    }

    cout << result << endl; // Print the final result
    return 0;
}

// <END-OF-CODE>
