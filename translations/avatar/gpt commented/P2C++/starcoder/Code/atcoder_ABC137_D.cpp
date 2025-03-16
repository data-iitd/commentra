#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Read the number of days (n) and the maximum number of jobs (m) from input
    int n, m;
    cin >> n >> m;

    // Initialize two heaps: one for jobs (x) and one for selected salaries (y)
    priority_queue<pair<int, int>> x;
    vector<int> y;

    // Read the job details for n days
    for (int i = 0; i < n; i++) {
        // For each day, read the day number and salary
        int day, salary;
        cin >> day >> salary;
        // Push the negative of day and salary onto the heap to create a max-heap
        x.push({-day, -salary});
    }

    // Process the jobs in the heap until it's empty
    while (!x.empty()) {
        // Pop the job with the highest day and salary (due to negation)
        int d, s = x.top().second;
        x.pop();

        // Calculate the remaining capacity for jobs
        int r = m - y.size();

        // If there is enough capacity to take the job
        if (r >= -d) {
            // Add the salary to the selected salaries heap
            y.push_back(s);
        } else {
            // If capacity is full, replace the lowest salary if the new salary is higher
            y.push_back(s);
            y.erase(y.begin());  // Remove the lowest salary from the heap
        }
    }

    // Output the total sum of selected salaries
    cout << accumulate(y.begin(), y.end(), 0) << endl;

    return 0;
}

