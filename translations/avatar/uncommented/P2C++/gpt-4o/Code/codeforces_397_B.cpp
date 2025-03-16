#include <iostream>
#include <vector>
#include <string>

class CodeforcesTask397BSolution {
public:
    std::string result;
    int t;
    std::vector<std::vector<int>> queries;

    void read_input() {
        std::cin >> t;
        queries.resize(t);
        for (int i = 0; i < t; ++i) {
            queries[i].resize(3);
            std::cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        }
    }

    void process_task() {
        std::vector<std::string> res;
        for (const auto& query : queries) {
            int k = query[0] / query[1];
            res.push_back(k * query[2] >= query[0] ? "Yes" : "No");
        }
        result = "";
        for (const auto& r : res) {
            result += r + "\n";
        }
    }

    std::string get_result() {
        return result;
    }
};

int main() {
    CodeforcesTask397BSolution solution;
    solution.read_input();
    solution.process_task();
    std::cout << solution.get_result();
    return 0;
}

// <END-OF-CODE>
