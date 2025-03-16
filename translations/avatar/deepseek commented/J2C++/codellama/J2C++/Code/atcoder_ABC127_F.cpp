#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    // Declare static members for output stream and print writer
    static FILE *outputStream = stdout;
    static PrintWriter out = new PrintWriter(outputStream);

    // Read the number of test cases
    int t;
    cin >> t;

    // Initialize priority queues for max and min values
    priority_queue<int> pqmax;
    priority_queue<int, vector<int>, greater<int>> pqmin;

    // Initialize variables to keep track of sums and the minimum value
    long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    // Process each test case
    while (t-- > 0) {
        // Read the input for the current test case
        string s;
        cin >> s;

        // If the command is '2', calculate and print the result
        if (s[0] == '2') {
            long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long ans1 = min;
            ans1 *= pqmax.size();
            ans1 = sumMax - ans1;
            out.println(min + " " + (ans + ans1 + sumb));
        } 
        // If the command is '1', add the new value to the appropriate priority queue
        else {
            int in = stoi(s.substr(1));
            sumb += stol(s.substr(3));

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

    // Close the print writer to flush the output
    out.close();

    return 0;
}

