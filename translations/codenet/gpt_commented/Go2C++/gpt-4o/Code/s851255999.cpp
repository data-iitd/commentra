#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a struct to represent a work item with time and limit
struct Work {
    int time, limit;
};

// Comparator function to sort work items based on their limits
bool compare(const Work &a, const Work &b) {
    return a.limit < b.limit;
}

// Entry point of the program
int main() {
    // Read the number of work items
    int n;
    cin >> n;

    // Initialize a vector to hold the work items
    vector<Work> works(n);

    // Read each work item's time and limit
    for (int i = 0; i < n; i++) {
        cin >> works[i].time >> works[i].limit; // Store the work item in the vector
    }

    // Sort the work items based on their limits
    sort(works.begin(), works.end(), compare);

    // Initialize a variable to keep track of the cumulative time
    long long sum = 0;

    // Check if the cumulative time exceeds the limit for any work item
    for (const auto &w : works) {
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

// <END-OF-CODE>
