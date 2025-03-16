#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Output stream for printing results
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read the number of test cases
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input

    // Priority queues for processing input
    priority_queue<int> pqmax; // Max-heap for maximum values
    priority_queue<int, vector<int>, greater<int>> pqmin; // Min-heap for minimum values

    // Variables to store sums and minimum value
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    // Process each test case
    while (t-- > 0) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int command;
        ss >> command;

        // If the first character is '2', calculate and print the result
        if (command == 2) {
            long long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long long ans1 = min;
            ans1 *= pqmax.size();
            ans1 = sumMax - ans1;

            // Print the minimum value and the calculated result
            cout << min << " " << (ans + ans1 + sumb) << "\n";
        } else {
            // Parse the input values
            int in;
            ss >> in;
            long long additionalValue;
            ss >> additionalValue;
            sumb += additionalValue; // Update the sum of additional values

            // Add the input value to the appropriate priority queue
            if (in > min) {
                pqmax.push(in);
                sumMax += in;
            } else {
                pqmin.push(in);
                sumMin += in;
            }

            // Balance the two heaps if necessary
            if (pqmin.size() > pqmax.size()) {
                sumMax += pqmin.top();
                sumMin -= pqmin.top();
                pqmax.push(pqmin.top());
                pqmin.pop();
            }
            if (pqmin.size() < pqmax.size()) {
                sumMax -= pqmax.top();
                sumMin += pqmax.top();
                pqmin.push(pqmax.top());
                pqmax.pop();
            }

            // Update the minimum value based on the current state of the heaps
            min = pqmin.top();
        }
    }

    return 0;
}

// <END-OF-CODE>
