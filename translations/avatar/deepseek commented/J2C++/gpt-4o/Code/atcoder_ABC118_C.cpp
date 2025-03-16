#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> func(vector<int> A) {
    vector<int> a = A; // Create a copy of the input vector
    int min = 0; // Initialize the minimum variable

    for (size_t i = 0; i < a.size(); i++) { // Iterate through the vector
        if (a[i] == 0) { // Remove elements that are zero
            a.erase(a.begin() + i);
            i--; // Adjust the index after removal
        } else { // Process non-zero elements
            if (min != 0) { // Check if min is not zero
                a[i] = a[i] % min; // Perform modulo operation
                if (a[i] == 1) { // Check if the result is 1
                    cout << 1 << endl; // Print 1 and exit the program
                    exit(0);
                }
            } else { // Find the minimum non-zero element
                min = a[i];
            }
        }
    }

    sort(a.begin(), a.end()); // Sort the vector
    return a; // Return the updated vector
}

int main() {
    int n;
    cin >> n; // Read the number of integers
    vector<int> a; // Create a vector to store integers

    if (n == 1) { // Check if there is only one integer
        int singleInt;
        cin >> singleInt; // Read the single integer
        cout << singleInt << endl; // Print the single integer
        return 0; // Exit the program
    }

    for (int i = 0; i < n; i++) { // Read n integers and add them to the vector
        int num;
        cin >> num;
        a.push_back(num);
    }

    sort(a.begin(), a.end()); // Sort the vector

    if (a.back() == 0) { // Check if the largest element is 0
        cout << 0 << endl; // Print 0 and exit the program
        return 0;
    }

    int ans = 0; // Initialize the result variable

    while (true) { // Enter an infinite loop to process the vector
        if (a.size() == 1) { // Check if there is only one element left
            ans = a[0]; // Assign the single element to ans
            break; // Exit the loop
        }
        a = func(a); // Call the func method to update the vector
    }

    cout << ans << endl; // Print the final result
    return 0;
}

// <END-OF-CODE>
