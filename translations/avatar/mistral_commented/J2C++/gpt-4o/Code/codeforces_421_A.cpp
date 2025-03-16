// Include necessary headers
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Define the main function
int main() {
    // Initialize variables
    int n, a, b;
    cin >> n; // Read the number of test cases
    cin >> a; // Read the number of elements in the first list
    cin >> b; // Read the number of elements in the second list

    // Create vectors to store the lists
    vector<int> list1(a);
    vector<int> list2(b);

    // Read and store the elements of the first and second lists
    for (int i = 0; i < a; i++) {
        cin >> list1[i]; // Read and add an element to list1
    }
    for (int i = 0; i < b; i++) {
        cin >> list2[i]; // Read and add an element to list2
    }

    // Use an unordered_set for faster lookup
    unordered_set<int> set1(list1.begin(), list1.end());

    // Iterate through the input array and print the corresponding number based on the presence of the element in list1
    for (int i = 0; i < n; i++) {
        if (set1.find(i + 1) != set1.end()) { // Check if the current input element is present in set1
            cout << 1 << " "; // If present, print 1
        } else {
            cout << 2 << " "; // If not present, print 2
        }
    }

    // End of the program
    return 0;
}

// <END-OF-CODE>
