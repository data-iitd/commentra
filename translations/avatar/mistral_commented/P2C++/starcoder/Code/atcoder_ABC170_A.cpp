
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read a list of space-separated integers as input from the standard input
    // and convert each integer to its corresponding C++ integer type using the stoi() function
    vector<int> a(istream_iterator<int>(cin), istream_iterator<int>());

    // Iterate over the elements of the list a using the C++ range-based for loop
    for (int i : a) {
        // Check if the current value is equal to zero
        if (i == 0) {
            // Print the index of the first zero to the standard output
            cout << distance(a.begin(), find(a.begin(), a.end(), 0)) + 1 << endl;
            // Terminate the loop using the break statement
            break;
        }
    }

    return 0;
}

