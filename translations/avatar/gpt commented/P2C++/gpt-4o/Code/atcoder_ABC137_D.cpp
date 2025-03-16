#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Read the number of days (n) and the maximum number of jobs (m) from input
    int n, m;
    cin >> n >> m;

    // Initialize two heaps: one for jobs (x) and one for selected salaries (y)
    priority_queue<pair<int, int>> x; // max-heap for jobs
    priority_queue<int, vector<int>, greater<int>> y; // min-heap for selected salaries

    // Read the job details for n days
    for (int i = 0; i < n; i++) {
        int day, salary;
        cin >> day >> salary;
        // Push the negative of day and salary onto the heap to create a max-heap
        x.push(make_pair(-day, -salary));
    }

    // Process the jobs in the heap until it's empty
    while (!x.empty()) {
        // Pop the job with the highest day and salary (due to negation)
        auto job = x.top();
        x.pop();
        int d = job.first;
        int s = job.second;

        // Calculate the remaining capacity for jobs
        int r = m - y.size();

        // If there is enough capacity to take the job
        if (r >= -d) {
            // Add the salary to the selected salaries heap
            y.push(-s);
        } else {
            // If capacity is full, replace the lowest salary if the new salary is higher
            y.push(-s);
            y.pop(); // Remove the lowest salary from the heap
        }
    }

    // Output the total sum of selected salaries
    int total = 0;
    while (!y.empty()) {
        total += y.top();
        y.pop();
    }
    cout << total << endl;

    return 0;
}

// <END-OF-CODE>
