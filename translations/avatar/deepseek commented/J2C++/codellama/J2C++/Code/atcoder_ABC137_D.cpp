#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Step 2: Define Job class
class Job {
public:
    int a;
    int b;

    Job(int a, int b) {
        this->a = a;
        this->b = b;
    }

    // Step 2: Implement compareTo method to compare jobs based on parameters a and b
    bool operator<(const Job& otherJob) const {
        if (otherJob.a == this->a)
            return this->b < otherJob.b;
        else
            return this->a < otherJob.a;
    }
};

int main() {
    // Step 4: Read input and initialize variables
    string line;
    getline(cin, line);
    istringstream iss(line);
    int N, M;
    iss >> N >> M;
    
    // Step 5: Create a priority queue to store jobs
    priority_queue<Job> q;
    
    // Step 6: Read job details and add to the priority queue
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        istringstream iss(line);
        int a, b;
        iss >> a >> b;
        q.push(Job(a, b));
    }
    
    // Step 7: Initialize counters and another priority queue
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> jobQ;
    
    // Step 8: Process each day from 1 to M
    for (int i = 1; i <= M; i++) {
        while (!q.empty()) {
            Job job = q.top();
            if (job.a <= i) {
                jobQ.push(q.top().b);
                q.pop();
            } else {
                break;
            }
        }
        if (!jobQ.empty())
            cnt += jobQ.top(), jobQ.pop();
    }
    
    // Step 10: Print the total reward
    cout << cnt << endl;
    
    return 0;
}

