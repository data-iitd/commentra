
#####
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CodeforcesTask397BSolution {
public:
    string result;
    int t;
    vector< vector<int> > queries;

    CodeforcesTask397BSolution() {
        result = "";
        t = 0;
    }

    void read_input() {
        cin >> t;
        for (int i = 0; i < t; ++i) {
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
        for (int i = 0; i < t; ++i) {
            int k = queries[i][0] / queries[i][1];
            res.push_back(k * queries[i][2] >= queries[i][0]? "Yes" : "No");
        }
        result = "";
        for (int i = 0; i < t; ++i) {
            result += res[i] + "\n";
        }
    }

    string get_result() {
        return result;
    }
};

int main() {
    CodeforcesTask397BSolution solution;
    solution.read_input();
    solution.process_task();
    cout << solution.get_result() << endl;
    return 0;
}
