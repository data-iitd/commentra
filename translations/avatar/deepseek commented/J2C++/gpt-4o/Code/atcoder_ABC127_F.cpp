#include <iostream> // For input/output operations
#include <queue> // For priority queues
#include <vector> // For vector
#include <string> // For string operations
#include <sstream> // For string stream
using namespace std;

int main() {
    // Initialize variables for input and output
    int t;
    cin >> t; // Read the number of test cases
    cin.ignore(); // Ignore the newline character after the integer input

    // Initialize priority queues for max and min values
    priority_queue<int> pqmax; // Max heap
    priority_queue<int, vector<int>, greater<int>> pqmin; // Min heap

    // Initialize variables to keep track of sums and the minimum value
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    // Process each test case
    while (t-- > 0) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        string command;
        ss >> command; // Read the command

        // If the command is '2', calculate and print the result
        if (command[0] == '2') {
            long long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long long ans1 = min;
            ans1 *= pqmax.size();
            ans1 = sumMax - ans1;
            cout << min << " " << (ans + ans1 + sumb) << endl;
        } 
        // If the command is '1', add the new value to the appropriate priority queue
        else {
            int in;
            long long value;
            ss >> in >> value; // Read the input values

            sumb += value;

            if (in > min) {
                pqmax.push(in);
                sumMax += in;
            } else {
                pqmin.push(in);
                sumMin += in;
            }

            // Balance the priority queues
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

            // Update the minimum value
            min = pqmin.top();
        }
    }

    return 0;
}

// <END-OF-CODE>
