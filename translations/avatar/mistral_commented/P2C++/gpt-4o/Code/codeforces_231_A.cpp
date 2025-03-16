#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Take an integer 'n' as input from the user
    int n;
    cin >> n;

    // Initialize a counter 'c' to 0
    int c = 0;

    // Iterate through the range of 'n'
    for (int i = 0; i < n; i++) {
        // Take 'n' lists of integers as input from the user
        vector<int> l1;
        int num;
        while (cin.peek() != '\n' && cin >> num) {
            l1.push_back(num);
        }
        cin.ignore(); // Ignore the newline character after the list input

        // Check if the sum of the elements in the current list is greater than 1
        int sum = 0;
        for (int j = 0; j < l1.size(); j++) {
            sum += l1[j];
        }
        if (sum > 1) {
            // Increment the counter 'c' by 1 if the condition is true
            c++;
        }
    }

    // Print the value of the counter 'c'
    cout << c << endl;

    return 0;
}

// <END-OF-CODE>
