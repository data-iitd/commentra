#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // Declare variables for the number of elements and sizes of the two lists
    int n, a, b;

    // Read the values for n, a, and b from the input
    cin >> n >> a >> b;

    // Initialize two vectors to store the elements of the two lists
    vector<int> list1(a);
    vector<int> list2(b);

    // Read 'a' integers into list1
    for (int i = 0; i < a; i++) {
        cin >> list1[i];
    }

    // Read 'b' integers into list2
    for (int i = 0; i < b; i++) {
        cin >> list2[i];
    }

    // Use an unordered_set for faster lookup
    unordered_set<int> set1(list1.begin(), list1.end());

    // Iterate from 0 to n-1 to check the presence of each index in list1
    for (int i = 0; i < n; i++) {
        // If the current index + 1 is in set1, print 1
        if (set1.find(i + 1) != set1.end()) {
            cout << 1 << " ";
        } else {
            // Otherwise, print 2
            cout << 2 << " ";
        }
    }

    return 0;
}

// <END-OF-CODE>
