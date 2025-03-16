#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Use a priority queue to store jobs with negative values for max-heap behavior
    priority_queue<tuple<int, int>> x;
    vector<int> y;

    // Read each job's day and salary, and push them into the priority queue x
    for (int i = 0; i < n; ++i) {
        int day, salary;
        cin >> day >> salary;
        x.push(make_tuple(-day, -salary));
    }

    // Process the jobs in the order of their deadlines
    while (!x.empty()) {
        // Pop the job with the largest deadline (negated values)
        auto [d, s] = x.top();
        x.pop();

        // Calculate the remaining days available for new jobs
        int r = m - static_cast<int>(y.size());

        // If there are enough days to accommodate this job
        if (r >= -d) {
            // Add the salary to the list of chosen salaries
            y.push_back(-s);
        } else {
            // If not enough days, check if we need to remove the smallest salary
            if (!y.empty()) {
                y.push_back(-s);
                // Remove the smallest salary
                auto min_it = min_element(y.begin(), y.end());
                y.erase(min_it);
            }
        }
    }

    // Output the sum of the chosen salaries
    int sum = 0;
    for (int salary : y) {
        sum += salary;
    }
    cout << sum << endl;

    return 0;
}
