#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Job {
public:
    int a;
    int b;

    Job(int a, int b) : a(a), b(b) {}

    bool operator<(const Job& other) const {
        if (this->a == other.a) {
            return this->b > other.b; // Min-heap based on b
        }
        return this->a > other.a; // Min-heap based on a
    }
};

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int N, M;
    char delimiter;
    ss >> N >> delimiter >> M;

    priority_queue<Job> q;
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        stringstream jobStream(line);
        int a, b;
        jobStream >> a >> delimiter >> b;
        q.push(Job(a, b));
    }

    int cnt = 0;
    priority_queue<int> jobQ; // Max-heap for job durations
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

    cout << cnt << endl;
    return 0;
}

// <END-OF-CODE>
