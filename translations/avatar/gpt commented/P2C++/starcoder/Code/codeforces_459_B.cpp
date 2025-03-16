#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read an integer input for the number of elements
    int n;
    cin >> n;

    // Read a line of input, split it into individual strings, convert them to integers, and store them in a list
    vector<int> l1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l1.push_back(x);
    }

    // Sort the list of integers in ascending order
    sort(l1.begin(), l1.end());

    // Assign the maximum value in the list to variable 'a'
    int a = l1.back();

    // Assign the minimum value in the list to variable 'b'
    int b = l1.front();

    // Check if the maximum and minimum values are the same
    if (a == b) {
        // If they are the same, the difference is zero and the number of pairs is n choose 2
        cout << a - b << " " << n * (n - 1) / 2 << endl;
    } else {
        // Count occurrences of the maximum value 'a' in the list
        int ac = count(l1.begin(), l1.end(), a);

        // Count occurrences of the minimum value 'b' in the list
        int bc = count(l1.begin(), l1.end(), b);

        // Calculate the difference between the maximum and minimum values, and the product of their counts
        cout << a - b << " " << ac * bc << endl;
    }

    return 0;
}
