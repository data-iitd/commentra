
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Class representing a Job with two attributes 'a' and 'b'
class Job {
public:
    int a; // Represents the time or priority of the job
    int b; // Represents the value or weight of the job

    // Constructor to initialize Job attributes
    Job(int a, int b) {
        this->a = a;
        this->b = b;
    }

    // Override operator< to define the ordering of Jobs
    bool operator<(const Job& otherJob) const {
        // Compare based on 'a' first, and if equal, then by 'b'
        if (otherJob.a == this->a)
            return this->b < otherJob.b;
        else
            return this->a < otherJob.a;
    }
};

int main() {
    // Create a Scanner object to read input
    cin.tie(0);
    ios::sync_with_stdio(false);

    // Read the first line of input and split it to get N and M
    int N, M;
    cin >> N >> M;

    // Create a priority queue to hold the jobs
    priority_queue<Job> q;

    // Read the job details and add them to the priority queue
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        q.push(Job(a, b));
    }

    int cnt = 0; // Counter to accumulate the total value of jobs processed
    priority_queue<int, vector<int>, greater<int>> jobQ; // Queue to hold job values in descending order

    // Process jobs for each time unit from 1 to M
    for (int i = 1; i <= M; i++) {
        // While there are jobs that can be processed at time i
        while (!q.empty()) {
            Job job = q.top(); // Peek at the job with the highest priority
            if (job.a <= i) { // If the job can be processed at time i
                jobQ.push(q.top().b); // Remove the job from the queue and add its value to jobQ
                q.pop();
            } else
                break; // Break if the job cannot be processed yet
        }
        // If there are jobs available to process, add the highest value job to the counter
        if (!jobQ.empty())
            cnt += jobQ.top(); // Poll the highest value job from jobQ and add to cnt
            jobQ.pop();
    }

    // Output the total value of jobs processed
    cout << cnt << endl; // Output the total value of jobs processed

    return 0;
}
