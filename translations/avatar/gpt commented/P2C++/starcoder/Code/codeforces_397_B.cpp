#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CodeforcesTask397BSolution {
public:
    CodeforcesTask397BSolution() {
        // Initialize the result string, number of queries, and a list to hold the queries
        result = "";
        t = 0;
        queries = vector<vector<int>>();
    }

    void read_input() {
        // Read the number of queries from input
        cin >> t;
        // Read each query and store it as a list of integers in the queries list
        for (int i = 0; i < t; i++) {
            vector<int> query;
            for (int j = 0; j < 3; j++) {
                int x;
                cin >> x;
                query.push_back(x);
            }
            queries.push_back(query);
        }
    }

    void process_task() {
        // Initialize a list to hold the results for each query
        vector<string> res;
        // Process each query to determine if the condition is met
        for (auto query : queries) {
            // Calculate how many complete sets of query[1] fit into query[0]
            int k = query[0] / query[1];
            // Check if k multiplied by query[2] is at least query[0]
            res.push_back("Yes" if k * query[2] >= query[0] else "No");
        }
        // Join the results into a single string separated by newlines
        result = "\n".join(res);
    }

    string get_result() {
        // Return the final result string
        return result;
    }

private:
    string result;
    int t;
    vector<vector<int>> queries;
};

int main() {
    // Create an instance of the solution class and run the processing
    CodeforcesTask397BSolution Solution;
    Solution.read_input();
    Solution.process_task();
    // Print the final result
    cout << Solution.get_result();
    return 0;
}

