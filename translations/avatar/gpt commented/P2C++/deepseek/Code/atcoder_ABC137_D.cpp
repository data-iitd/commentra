#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize two priority queues: one for jobs (x) and one for selected salaries (y)
    priority_queue<tuple<int, int>> x;
    priority_queue<int, vector<int>, greater<int>> y;

    // Read the job details for n days
    for (int i = 0; i < n; ++i) {
        int day, salary;
        cin >> day >> salary;
        // Push the negative of day and salary onto the queue to create a max-heap
        x.push(make_tuple(-day, -salary));
    }

    // Process the jobs in the queue until it's empty
    while (!x.empty()) {
        // Pop the job with the highest day and salary (due to negation)
        auto [d, s] = x.top();
        x.pop();

        // Calculate the remaining capacity for jobs
        int r = m - y.size();

        // If there is enough capacity to take the job
        if (r >= -d) {
            // Add the salary to the selected salaries queue
            y.push(-s);
        } else {
            // If capacity is full, replace the lowest salary if the new salary is higher
            y.push(-s);
            y.pop();  // Remove the lowest salary from the queue
        }
    }

    // Output the total sum of selected salaries
    int total_salary = 0;
    while (!y.empty()) {
        total_salary += y.top();
        y.pop();
    }
    cout << total_salary << endl;

    return 0;
}
