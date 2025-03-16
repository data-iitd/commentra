#include <iostream> // For handling input and output
#include <queue> // For using priority queues
#include <vector> // For using vectors
#include <string> // For using strings
#include <sstream> // For using string streams

using namespace std;

int main() {
    ios::sync_with_stdio(false); // Optimize input/output
    cin.tie(nullptr); // Untie cin from cout

    int t;
    cin >> t; // Read the number of test cases
    cin.ignore(); // Ignore the newline character after the integer input

    priority_queue<int> pqmax; // Max Heap to store the maximum elements
    priority_queue<int, vector<int>, greater<int>> pqmin; // Min Heap to store the minimum elements
    long long sumMin = 0, sumMax = 0, sumb = 0; // Variables to store the sums
    int min = 0; // Variable to store the minimum element

    while (t-- > 0) { // Loop through all the test cases
        string line;
        getline(cin, line); // Read each line of input

        stringstream ss(line);
        int command;
        ss >> command; // Read the command

        if (command == 2) { // If the command is '2'
            long long ans = min; // Answer is the product of the minimum element and the size of the min heap
            ans *= pqmin.size();
            ans -= sumMin; // Subtract the sum of minimum elements before the current minimum
            long long ans1 = min; // Answer1 is the product of the minimum element and the size of the max heap
            ans1 = sumMax - ans1; // Subtract the sum of maximum elements before the current minimum
            cout << min << " " << (ans + ans1 + sumb) << "\n"; // Print the answer
        } else { // Else the command is not '2'
            int in;
            ss >> in; // Read the integer value from the input
            long long currentValue;
            ss >> currentValue; // Read the long value

            sumb += currentValue; // Add the long value to the sum of the current element

            if (in > min) { // If the input is greater than the current minimum
                pqmax.push(in); // Add the input to the max heap
                sumMax += in; // Add the input to the sum of maximum elements
            } else { // Else the input is smaller than the current minimum
                pqmin.push(in); // Add the input to the min heap
                sumMin += in; // Add the input to the sum of minimum elements
            }

            // Balancing the heaps
            if (pqmin.size() > pqmax.size()) { // If the size of min heap is greater than the size of max heap
                sumMax += pqmin.top(); // Add the minimum element to the sum of maximum elements
                sumMin -= pqmin.top(); // Subtract the minimum element from the sum of minimum elements
                pqmax.push(pqmin.top()); // Add the polled element from min heap to max heap
                pqmin.pop(); // Remove the element from min heap
            } else if (pqmin.size() < pqmax.size()) { // Else if the size of min heap is smaller than the size of max heap
                sumMax -= pqmax.top(); // Subtract the maximum element from the sum of maximum elements
                sumMin += pqmax.top(); // Add the maximum element to the sum of minimum elements
                pqmin.push(pqmax.top()); // Add the polled element from max heap to min heap
                pqmax.pop(); // Remove the element from max heap
            }

            min = pqmin.top(); // Update the minimum element
        }
    }

    return 0; // End of the program
}

// <END-OF-CODE>
