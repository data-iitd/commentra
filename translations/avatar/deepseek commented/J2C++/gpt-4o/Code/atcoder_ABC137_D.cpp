#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Step 2: Define Job class
class Job {
public:
    int a;
    int b;

    Job(int a, int b) : a(a), b(b) {}

    // Step 2: Implement comparison operator to compare jobs based on parameters a and b
    bool operator<(const Job& otherJob) const {
        if (this->a == otherJob.a)
            return this->b > otherJob.b; // For max-heap behavior
        return this->a > otherJob.a; // For min-heap behavior
    }
};

int main() {
    // Step 4: Read input and initialize variables
    string line;
    getline(cin, line);
    stringstream ss(line);
    int N, M;
    ss >> N >> M;

    // Step 5: Create a priority queue to store jobs
    priority_queue<Job> q;

    // Step 6: Read job details and add to the priority queue
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        stringstream jobStream(line);
        int a, b;
        jobStream >> a >> b;
        q.push(Job(a, b));
    }

    // Step 7: Initialize counters and another priority queue
    int cnt = 0;
    priority_queue<int> jobQ;

    // Step 8: Process each day from 1 to M
    for (int i = 1; i <= M; i++) {
        while (!q.empty()) {
            Job job = q.top();
            if (job.a <= i) {
                jobQ.push(job.b);
                q.pop();
            } else {
                break;
            }
        }
        if (!jobQ.empty()) {
            cnt += jobQ.top();
            jobQ.pop();
        }
    }

    // Step 10: Print the total reward
    cout << cnt << endl;

    return 0;
}

// <END-OF-CODE>
