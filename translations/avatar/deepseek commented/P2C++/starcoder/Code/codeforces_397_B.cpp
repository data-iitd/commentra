
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CodeforcesTask397BSolution {
public:
    string result;
    int t;
    vector<vector<int>> queries;

    void read_input() {
        cin >> t;
        for (int i = 0; i < t; i++) {
            vector<int> query;
            int a, b, c;
            cin >> a >> b >> c;
            query.push_back(a);
            query.push_back(b);
            query.push_back(c);
            queries.push_back(query);
        }
    }

    void process_task() {
        vector<string> res;
        for (auto query : queries) {
            int k = query[0] / query[1];
            if (k * query[2] >= query[0]) {
                res.push_back("Yes");
            } else {
                res.push_back("No");
            }
        }
        result = "\n".join(res);
    }

    string get_result() {
        return result;
    }
};

int main() {
    CodeforcesTask397BSolution Solution;
    Solution.read_input();
    Solution.process_task();
    cout << Solution.get_result();
    return 0;
}

