#######
#include <bits/stdc++.h>
using namespace std;

// Class definition for CodeforcesTask397BSolution
class CodeforcesTask397BSolution {
public:
    string result;
    int t;
    vector<vector<int>> queries;

    // Constructor method with initializations
    CodeforcesTask397BSolution() {
        result = "";
        t = 0;
        queries = vector<vector<int>>();
    }

    // Method to read input
    void read_input() {
        cin >> t;
        queries = vector<vector<int>>(t);
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> queries[i][j];
            }
        }
    }

    // Method to process the task
    void process_task() {
        vector<string> res;
        for (auto query : queries) {
            int k = query[0] / query[1];
            res.push_back(k * query[2] >= query[0]? "Yes" : "No");
        }
        result = "\n".join(res);
    }

    // Method to get the result
    string get_result() {
        return result;
    }
};

// Main method to run the code
int main() {
    CodeforcesTask397BSolution Solution;
    Solution.read_input();
    Solution.process_task();
    cout << Solution.get_result();
    return 0;
}

