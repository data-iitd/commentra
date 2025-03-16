#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> func(vector<int> A) {
    vector<int> a = A;
    int min = 0;

    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            a.erase(a.begin() + i);
            i--; // Adjust index after removal
        } else {
            if (min != 0) {
                a[i] = a[i] % min;
                if (a[i] == 1) {
                    cout << 1 << endl;
                    exit(0);
                }
            } else {
                min = a[i];
            }
        }
    }

    sort(a.begin(), a.end());
    return a;
}

int main() {
    // Create a variable to read input from the user
    int n;
    cin >> n;

    // Initialize a vector to store the integers
    vector<int> a;

    // If there is only one integer, print it and exit
    if (n == 1) {
        int singleValue;
        cin >> singleValue;
        cout << singleValue << endl;
        return 0;
    }

    // Read n integers from input and add them to the vector
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        a.push_back(value);
    }

    // Sort the vector in ascending order
    sort(a.begin(), a.end());

    // If the largest number is 0, print 0 and exit
    if (a.back() == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Initialize the answer variable
    int ans = 0;

    // Loop until the vector is reduced to one element
    while (true) {
        // If only one element remains, set it as the answer and break the loop
        if (a.size() == 1) {
            ans = a[0];
            break;
        }
        // Call the function to process the vector and update it
        a = func(a);
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
