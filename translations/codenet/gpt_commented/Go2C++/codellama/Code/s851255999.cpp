#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a struct to represent a work item with time and limit
struct work {
    int time, limit;
};

// Define a vector of work items
vector<work> ws;

// Implement the sort.Interface for works
bool compare(work a, work b) {
    return a.limit < b.limit;
}

// Entry point of the program
int main() {
    // Read the number of work items
    int n;
    cin >> n;

    // Initialize a vector to hold the work items
    ws.resize(n);

    // Read each work item's time and limit
    for (int i = 0; i < n; i++) {
        int a, n;
        cin >> a >> n;
        ws[i] = {a, n}; // Store the work item in the vector
    }

    // Sort the work items based on their limits
    sort(ws.begin(), ws.end(), compare);

    // Initialize a variable to keep track of the cumulative time
    long long sum = 0;

    // Check if the cumulative time exceeds the limit for any work item
    for (auto w : ws) {
        sum += w.time; // Add the current work item's time to the sum
        if (sum > w.limit) {
            cout << "No" << endl; // If the sum exceeds the limit, print "No"
            return 0;
        }
    }

    // If all work items are within their limits, print "Yes"
    cout << "Yes" << endl;

    return 0;
}

