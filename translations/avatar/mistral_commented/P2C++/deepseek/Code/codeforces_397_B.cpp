#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class CodeforcesTask397BSolution {
private:
    std::string result;
    int t;
    std::vector<std::vector<int>> queries;

public:
    CodeforcesTask397BSolution() : result(""), t(0), queries(std::vector<std::vector<int>>()) {}

    void readInput() {
        std::cin >> t;
        queries.resize(t);
        for (int i = 0; i < t; ++i) {
            for (int j = 0; j < 3; ++j) {
                int x;
                std::cin >> x;
                queries[i].push_back(x);
            }
        }
    }

    void processTask() {
        std::vector<std::string> res;
        for (const auto& query : queries) {
            int k = query[0] / query[1];
            res.push_back(k * query[2] >= query[0] ? "Yes" : "No");
        }
        std::ostringstream oss;
        for (size_t i = 0; i < res.size(); ++i) {
            if (i > 0) oss << "\n";
            oss << res[i];
        }
        result = oss.str();
    }

    std::string getResult() const {
        return result;
    }
};

int main() {
    CodeforcesTask397BSolution solution;
    solution.readInput();
    solution.processTask();
    std::cout << solution.getResult() << std::endl;
    return 0;
}

