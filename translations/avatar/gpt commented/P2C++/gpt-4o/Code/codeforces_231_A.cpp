#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Read an integer input which represents the number of lists to process
    int n;
    cin >> n;

    // Initialize a counter to keep track of lists with a sum greater than 1
    int c = 0;

    // Loop through the range of n to process each list
    for (int i = 0; i < n; i++) {
        // Read a line of input and store it in a vector
        vector<int> l1;
        int num;
        while (cin.peek() != '\n' && cin >> num) {
            l1.push_back(num);
        }
        cin.ignore(); // Ignore the newline character after the list input

        // Check if the sum of the current list is greater than 1
        int sum = 0;
        for (int j = 0; j < l1.size(); j++) {
            sum += l1[j];
        }
        if (sum > 1) {
            // Increment the counter if the condition is met
            c++;
        }
    }

    // Print the final count of lists that had a sum greater than 1
    cout << c << endl;

    return 0;
}
// <END-OF-CODE>
