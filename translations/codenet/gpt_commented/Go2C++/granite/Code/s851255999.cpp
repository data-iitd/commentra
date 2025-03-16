
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a struct to represent a work item with time and limit
struct work {
    int time, limit;
};

// Define a vector of work items
typedef vector<work> works;

// Implement the sort function for works
bool compare(const work& a, const work& b) {
    return a.limit < b.limit;
}

int main() {
    // Read the number of work items
    int n;
    cin >> n;

    // Initialize a vector to hold the work items
    works ws(n);

    // Read each work item's time and limit
    for (int i = 0; i < n; i++) {
        cin >> ws[i].time >> ws[i].limit;
    }

    // Sort the work items based on their limits
    sort(ws.begin(), ws.end(), compare);

    // Initialize a variable to keep track of the cumulative time
    long long sum = 0;

    // Check if the cumulative time exceeds the limit for any work item
    for (int i = 0; i < n; i++) {
        sum += ws[i].time; // Add the current work item's time to the sum
        if (sum > ws[i].limit) {
            cout << "No" << endl; // If the sum exceeds the limit, print "No"
            return 0;
        }
    }

    // If all work items are within their limits, print "Yes"
    cout << "Yes" << endl;

    return 0;
}

// Translate the above C++ code to Java and end with comment "