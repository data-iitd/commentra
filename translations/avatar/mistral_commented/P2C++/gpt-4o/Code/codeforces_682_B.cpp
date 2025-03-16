#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read a list of integers from standard input
vector<int> readIntegers() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    return numbers;
}

int main() {
    // Read the list of integers
    vector<int> l = readIntegers();

    // Initialize variable 'c' to 0
    int c = 0;

    // Sort the list 'l' in ascending order
    sort(l.begin(), l.end());

    // Iterate through the list 'l'
    for (int i : l) {
        // If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
        if (i > c) {
            c++;
        }
    }

    // Print the final result, which is the number of unique elements in the list 'l' plus 1
    cout << c + 1 << endl;

    return 0;
}

// <END-OF-CODE>
