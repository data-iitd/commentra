#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure named "work" with two fields: "time" and "limit" of type int
struct work {
    int time, limit;
};

// Comparator function to sort works based on the "limit" field
bool compare(const work &a, const work &b) {
    return a.limit < b.limit;
}

int main() {
    // Declare variables and initialize them
    int n;
    cin >> n;

    // Create a vector of work structures with size "n"
    vector<work> ws(n);

    // Read input data for each work structure and store it in the corresponding index of the "ws" vector
    for (int i = 0; i < n; i++) {
        cin >> ws[i].time >> ws[i].limit;
    }

    // Sort the "ws" vector based on the "limit" field of each work structure
    sort(ws.begin(), ws.end(), compare);

    // Initialize a variable named "sum" of type long long and set its value to 0
    long long sum = 0;

    // Iterate through the sorted "ws" vector and check if the total time spent on all works exceeds any work's limit
    for (const auto &w : ws) {
        // Add the time of the current work structure to the "sum" variable
        sum += w.time;

        // Check if the sum is greater than the limit of the current work structure
        if (sum > w.limit) {
            // If it is, print "No" and return from the function
            cout << "No" << endl;
            return 0;
        }
    }

    // If the loop completes without finding a work structure whose time exceeds its limit, print "Yes"
    cout << "Yes" << endl;

    return 0;
}

// <END-OF-CODE>
