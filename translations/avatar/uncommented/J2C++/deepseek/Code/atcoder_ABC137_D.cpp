#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job {
    int a, b;
    Job(int a, int b) : a(a), b(b) {}
};

struct CompareJob {
    bool operator()(const Job& j1, const Job& j2) {
        if (j1.a == j2.a) return j1.b > j2.b;
        return j1.a > j2.a;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<Job, vector<Job>, CompareJob> q;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        q.push(Job(a, b));
    }
    int cnt = 0;
    priority_queue<int> jobQ;
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

