#include <iostream>
#include <vector>
#include <string>

class CodeforcesTask397BSolution {
public:
    // Initialize the result string, number of queries, and a vector to hold the queries
    std::string result;
    int t;
    std::vector<std::vector<int>> queries;

    void read_input() {
        // Read the number of queries from input
        std::cin >> t;
        // Read each query and store it as a vector of integers in the queries vector
        queries.resize(t);
        for (int i = 0; i < t; ++i) {
            queries[i].resize(3);
            std::cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        }
    }

    void process_task() {
        // Initialize a vector to hold the results for each query
        std::vector<std::string> res;
        // Process each query to determine if the condition is met
        for (const auto& query : queries) {
            // Calculate how many complete sets of query[1] fit into query[0]
            int k = query[0] / query[1];
            // Check if k multiplied by query[2] is at least query[0]
            res.push_back(k * query[2] >= query[0] ? "Yes" : "No");
        }
        // Join the results into a single string separated by newlines
        result = "";
        for (const auto& r : res) {
            result += r + "\n";
        }
    }

    std::string get_result() {
        // Return the final result string
        return result;
    }
};

int main() {
    // Create an instance of the solution class
    CodeforcesTask397BSolution solution;
    // Read input data
    solution.read_input();
    // Process the task based on the input data
    solution.process_task();
    // Print the final results
    std::cout << solution.get_result();
    return 0;
}

// <END-OF-CODE>
