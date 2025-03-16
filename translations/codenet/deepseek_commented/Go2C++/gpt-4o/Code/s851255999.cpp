#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Work {
    int time;
    int limit;
};

bool compare(const Work &a, const Work &b) {
    return a.limit < b.limit;
}

int main() {
    // Read the number of works
    int n;
    cin >> n;

    // Create a vector of work structs
    vector<Work> works(n);

    // Read the time and limit for each work and store them in the vector
    for (int i = 0; i < n; i++) {
        cin >> works[i].time >> works[i].limit;
    }

    // Sort the vector of works based on the limit field
    sort(works.begin(), works.end(), compare);

    // Initialize a sum variable to keep track of the cumulative time
    long long sum = 0;

    // Iterate over the sorted vector of works, adding the time of each work to the sum
    for (const auto &w : works) {
        sum += w.time;

        // Check if the cumulative time exceeds the limit of the current work
        if (sum > w.limit) {
            cout << "No" << endl;
            return 0;
        }
    }

    // If the loop completes without the sum exceeding any limit, print "Yes"
    cout << "Yes" << endl;

    return 0;
}

// <END-OF-CODE>
