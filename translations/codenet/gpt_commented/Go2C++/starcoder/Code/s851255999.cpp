#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a struct to represent a work item with time and limit
struct work {
    int time;
    int limit;
};

// Define a vector of work items
typedef vector<work> works;

// Implement the sort.Interface for works
struct sorter {
    bool operator()(const work& a, const work& b) {
        return a.limit < b.limit;
    }
};

// Entry point of the program
int main() {
    // Read the number of work items
    int n;
    cin >> n;

    // Initialize a vector to hold the work items
    works ws(n);

    // Read each work item's time and limit
    for (int i = 0; i < n; i++) {
        int a, n;
        cin >> a >> n;
        ws[i] = work{a, n}; // Store the work item in the vector
    }

    // Sort the work items based on their limits
    sort(ws.begin(), ws.end(), sorter());

    // Initialize a variable to keep track of the cumulative time
    int64_t sum = 0;

    // Check if the cumulative time exceeds the limit for any work item
    for (const work& w : ws) {
        sum += w.time; // Add the current work item's time to the sum
        if (sum > w.limit) {
            cout << "No" << endl; // If the sum exceeds the limit, print "No"
            return 0;
        }
    }

    // If all work items are within their limits, print "Yes"
    cout << "Yes" << endl;
}

