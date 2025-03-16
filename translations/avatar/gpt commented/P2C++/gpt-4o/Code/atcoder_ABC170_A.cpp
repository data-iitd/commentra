#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Read a line of input and split it into components
    vector<int> a;
    int num;
    while (cin >> num) {
        a.push_back(num);
        if (cin.peek() == '\n') break; // Stop reading on newline
    }

    // Iterate over the vector 'a' using a for loop
    for (size_t e = 0; e < a.size(); ++e) {
        // Check if the current value is zero
        if (a[e] == 0) {
            // Print the index (1-based) of the first occurrence of zero
            cout << e + 1 << endl;
            // Exit the loop after finding the first zero
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
