#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct Job {
    int a;
    int b;

    Job(int a, int b) : a(a), b(b) {}
};

struct CompareJob {
    bool operator()(const Job& j1, const Job& j2) {
        if (j1.a == j2.a) {
            return j1.b > j2.b;
        } else {
            return j1.a > j2.a;
        }
    }
};

int main() {
    string line;
    int N, M;

    getline(cin, line);
    stringstream ss(line);
    string delimiter = "\u2581";
    vector<string> tokens;
    size_t pos = 0;
    while ((pos = line.find(delimiter)) != string::npos) {
        tokens.push_back(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());
    }
    tokens.push_back(line);

    N = stoi(tokens[0]);
    M = stoi(tokens[1]);

    priority_queue<Job, vector<Job>, CompareJob> q;

    for (int i = 0; i < N; i++) {
        getline(cin, line);
        stringstream ss(line);
        vector<string> jobTokens;
        while ((pos = line.find(delimiter)) != string::npos) {
            jobTokens.push_back(line.substr(0, pos));
            line.erase(0, pos + delimiter.length());
        }
        jobTokens.push_back(line);

        q.push(Job(stoi(jobTokens[0]), stoi(jobTokens[1])));
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
