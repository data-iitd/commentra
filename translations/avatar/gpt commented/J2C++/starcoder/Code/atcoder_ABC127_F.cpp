#include <bits/stdc++.h>
using namespace std;

// Output stream for printing results
ostream* outputStream = &cout;

// Function to print the result
void printResult(int min, long long sumMin, long long sumMax, long long sumb) {
    // Calculate the result
    long long ans = min;
    ans *= pqmin.size();
    ans -= sumMin;
    long long ans1 = min;
    ans1 *= pqmax.size();
    ans1 = sumMax - ans1;
    
    // Print the minimum value and the calculated result
    *outputStream << min << " " << (ans + ans1 + sumb) << endl;
}

// Main function
int main() {
    // Read the number of test cases
    int t;
    cin >> t;
    
    // Arrays and priority queues for processing input
    string s;
    priority_queue<int> pqmax; // Min-heap for maximum values
    priority_queue<int, vector<int>, greater<int>> pqmin; // Max-heap for minimum values
    
    // Variables to store sums and minimum value
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;
    
    // Process each test case
    while (t-- > 0) {
        // Read the input line and split it into parts
        cin >> s;
        
        // If the first character is '2', calculate and print the result
        if (s[0] == '2') {
            printResult(min, sumMin, sumMax, sumb);
        } else {
            // Parse the input values
            int in;
            cin >> in;
            sumb += stoll(s.substr(2)); // Update the sum of additional values
            
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
    
    // Close the output stream
    outputStream->close();
}

