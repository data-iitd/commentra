#include <iostream>
#include <vector>
#include <string>

class CodeforcesTask397BSolution {
public:
    std::string result;
    int t;
    std::vector<std::vector<int>> queries;

    // Reads the number of test cases and the queries from input
    void read_input() {
        std::cin >> t;  // Read the number of test cases
        queries.resize(t);
        for (int i = 0; i < t; ++i) {
            queries[i].resize(3);
            std::cin >> queries[i][0] >> queries[i][1] >> queries[i][2];  // Read each query
        }
    }

    // Processes each query to determine if the condition is met
    void process_task() {
        std::vector<std::string> res;
        for (const auto& query : queries) {
            int k = query[0] / query[1];  // Calculate k as the integer division of query[0] by query[1]
            res.push_back((k * query[2] >= query[0]) ? "Yes" : "No");  // Append "Yes" or "No" based on the condition
        }
        result = join(res, "\n");  // Join the results into a single string with newline characters
    }

    // Returns the final result
    std::string get_result() {
        return result;
    }

private:
    // Helper function to join strings with a delimiter
    std::string join(const std::vector<std::string>& vec, const std::string& delimiter) {
        std::string joined;
        for (size_t i = 0; i < vec.size(); ++i) {
            joined += vec[i];
            if (i < vec.size() - 1) {
                joined += delimiter;
            }
        }
        return joined;
    }
};

int main() {
    CodeforcesTask397BSolution solution;
    solution.read_input();
    solution.process_task();
    std::cout << solution.get_result() << std::endl;  // Print the final result
    return 0;
}

// <END-OF-CODE>
