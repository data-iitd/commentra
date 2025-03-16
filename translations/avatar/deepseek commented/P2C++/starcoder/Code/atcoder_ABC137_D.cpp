
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Read the number of jobs and the maximum number of days available
    int n, m;
    cin >> n >> m;

    // Initialize lists to store job days and salaries
    vector<int> x;
    vector<int> y;

    // Read each job's day and salary, and push them into the heap x
    for (int i = 0; i < n; i++) {
        int day, salary;
        cin >> day >> salary;
        // Push the day and salary as negative values to simulate a max-heap
        x.push_back(-day);
        x.push_back(-salary);
    }

    // Process the jobs in the order of their deadlines
    while (x.size() > 0) {
        // Pop the job with the largest deadline (negated values)
        int d = x.back();
        x.pop_back();
        int s = x.back();
        x.pop_back();

        // Calculate the remaining days available for new jobs
        int r = m - y.size();

        // If there are enough days to accommodate this job
        if (r >= -d) {
            // Add the salary to the list of chosen salaries
            y.push_back(-s);
        } else {
            // If not enough days, check if we need to remove the smallest salary
            if (y.size() > 0) {
                y.pop_back();
            }
            y.push_back(-s);
        }
    }

    // Output the sum of the chosen salaries
    cout << -y[0];

    return 0;
}

