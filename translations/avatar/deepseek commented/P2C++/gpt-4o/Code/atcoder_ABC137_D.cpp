#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Read the number of jobs and the maximum number of days available
    int n, m;
    cin >> n >> m;

    // Initialize a max-heap for jobs based on deadlines and salaries
    priority_queue<pair<int, int>> jobHeap;

    // Read each job's day and salary, and push them into the heap
    for (int i = 0; i < n; i++) {
        int day, salary;
        cin >> day >> salary;
        // Push the day and salary as negative values to simulate a max-heap
        jobHeap.push({day, salary});
    }

    // Initialize a min-heap for the chosen salaries
    priority_queue<int, vector<int>, greater<int>> salaryHeap;

    // Process the jobs in the order of their deadlines
    while (!jobHeap.empty()) {
        // Get the job with the largest deadline
        auto job = jobHeap.top();
        jobHeap.pop();

        // Calculate the remaining days available for new jobs
        int r = m - salaryHeap.size();

        // If there are enough days to accommodate this job
        if (r >= job.first) {
            // Add the salary to the list of chosen salaries
            salaryHeap.push(job.second);
        } else {
            // If not enough days, check if we need to remove the smallest salary
            salaryHeap.push(job.second);
            salaryHeap.pop();
        }
    }

    // Output the sum of the chosen salaries
    int totalSalary = 0;
    while (!salaryHeap.empty()) {
        totalSalary += salaryHeap.top();
        salaryHeap.pop();
    }
    cout << totalSalary << endl;

    return 0;
}

// <END-OF-CODE>
