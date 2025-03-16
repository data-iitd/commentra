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
            int k;
            cin >> k;
            query.push_back(k);
            for (int j = 0; j < 3; j++) {
                int x;
                cin >> x;
                query.push_back(x);
            }
            queries.push_back(query);
        }
    }
    void process_task() {
        vector<string> res;
        for (auto query : queries) {
            int k = query[0] / query[1];
            res.push_back(k * query[2] >= query[0]? "Yes" : "No");
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
