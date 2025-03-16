#include <bits/stdc++.h>

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
};

// Step 3: Define comparator class
class JobComparator {
public:
    bool operator()(Job j1, Job j2) {
        if (j1.a == j2.a)
            return j1.b > j2.b;
        else
            return j1.a < j2.a;
    }
};

int main() {
    // Step 4: Read input and initialize variables
    int N, M;
    cin >> N >> M;
    
    // Step 5: Create a priority queue to store jobs
    priority_queue<Job, vector<Job>, JobComparator> q;
    
    // Step 6: Read job details and add to the priority queue
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
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
            cnt += jobQ.top();
    }
    
    // Step 10: Print the total reward
    cout << cnt << endl;
}

