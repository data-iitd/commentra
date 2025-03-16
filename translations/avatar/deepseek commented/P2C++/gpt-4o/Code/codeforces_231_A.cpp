#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Take an integer input `n` which represents the number of lists to be provided as input.
    int n;
    cin >> n;

    // Initialize a counter `c` to 0. This will keep track of the number of lists where the sum of elements is greater than 1.
    int c = 0;

    // Loop `n` times to process each list of integers.
    for (int i = 0; i < n; i++) {
        // Take a list of integers as input.
        vector<int> l1;
        int num;
        while (cin.peek() != '\n' && cin >> num) {
            l1.push_back(num);
        }
        cin.ignore(); // Ignore the newline character after the list input.

        // Calculate the sum of the elements in `l1`.
        int sum = 0;
        for (int j = 0; j < l1.size(); j++) {
            sum += l1[j];
        }

        // If the sum is greater than 1, increment the counter `c` by 1.
        if (sum > 1) {
            c++;
        }
    }

    // After the loop completes, print the final value of `c`, which represents the number of lists where the sum of elements is greater than 1.
    cout << c << endl;

    return 0;
}

// <END-OF-CODE>
