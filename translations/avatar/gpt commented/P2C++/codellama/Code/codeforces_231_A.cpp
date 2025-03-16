#include <iostream>
#include <string>
#include <sstream>
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
        // Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<int> l1;
        int temp;
        while (iss >> temp) {
            l1.push_back(temp);
        }

        // Check if the sum of the current list is greater than 1
        if (sum(l1.begin(), l1.end()) > 1) {
            // Increment the counter if the condition is met
            c++;
        }
    }

    // Print the final count of lists that had a sum greater than 1
    cout << c << endl;

    return 0;
}

