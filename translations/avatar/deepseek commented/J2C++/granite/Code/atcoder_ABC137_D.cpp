
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// Step 2: Define Job class
class Job {
public:
    int a, b;
    Job(int a, int b) : a(a), b(b) {}
    bool operator<(const Job& other) const {
        if (a == other.a)
            return b < other.b;
        else
            return a < other.a;
    }
};

int main() {
    // Step 4: Read input and initialize variables
    string line;
    getline(cin, line);
    int N, M;
    sscanf(line.c_str(), "%d %d", &N, &M);
    
    // Step 5: Create a priority queue to store jobs
    priority_queue<Job> q;
    
    // Step 6: Read job details and add to the priority queue
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        int a, b;
        sscanf(line.c_str(), "%d %d", &a, &b);
        q.push(Job(a, b));
    }
    
    // Step 7: Initialize counters and another priority queue
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> jobQ;
    
    // Step 8: Process each day from 1 to M
    for (int i = 1; i <= M; i++) {
        while (!q.empty() && q.top().a <= i) {
            jobQ.push(q.top().b);
            q.pop();
        }
        if (!jobQ.empty())
            cnt += jobQ.top(), jobQ.pop();
    }
    
    // Step 10: Print the total reward
    cout << cnt << endl;
    
    return 0;
}

