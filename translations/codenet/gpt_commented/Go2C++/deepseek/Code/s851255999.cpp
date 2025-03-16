#include <iostream>
#include <vector>
#include <algorithm>

// Define a struct to represent a work item with time and limit
struct work {
    int time;
    int limit;
};

// Define a vector of work items
using works = std::vector<work>;

int main() {
    // Read the number of work items
    int n;
    std::cin >> n;

    // Initialize a vector to hold the work items
    works ws(n);

    // Read each work item's time and limit
    for (int i = 0; i < n; i++) {
        std::cin >> ws[i].time >> ws[i].limit;
    }

    // Sort the work items based on their limits
    std::sort(ws.begin(), ws.end(), [](const work& a, const work& b) {
        return a.limit < b.limit;
    });

    // Initialize a variable to keep track of the cumulative time
    int64_t sum = 0;

    // Check if the cumulative time exceeds the limit for any work item
    for (const auto& w : ws) {
        sum += w.time; // Add the current work item's time to the sum
        if (sum > w.limit) {
            std::cout << "No" << std::endl; // If the sum exceeds the limit, print "No"
            return 0;
        }
    }

    // If all work items are within their limits, print "Yes"
    std::cout << "Yes" << std::endl;

    return 0;
}
