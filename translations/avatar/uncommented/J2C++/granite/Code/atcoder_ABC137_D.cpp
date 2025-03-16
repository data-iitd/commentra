
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int a, b;
    Job(int a, int b) : a(a), b(b) {}
    bool operator<(const Job& other) const {
        if (a == other.a) return b < other.b;
        return a < other.a;
    }
};

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int N, M;
    ss >> N >> M;
    priority_queue<Job> q;
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        ss.clear();
        ss.str(line);
        int a, b;
        ss >> a >> b;
        q.push(Job(a, b));
    }
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> jobQ;
    for (int i = 1; i <= M; i++) {
        while (!q.empty() && q.top().a <= i) {
            jobQ.push(q.top().b);
            q.pop();
        }
        if (!jobQ.empty()) {
            cnt += jobQ.top();
            jobQ.pop();
        }
    }
    cout << cnt << endl;
    return 0;
}
