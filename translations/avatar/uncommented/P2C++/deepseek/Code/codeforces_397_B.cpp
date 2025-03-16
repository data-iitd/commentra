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
        std::stringstream ss;
        for (const auto& s : res) {
            ss << s << "\n";
        }
        result = ss.str();
    }

    std::string getResult() const {
        return result;
    }
};

int main() {
    CodeforcesTask397BSolution solution;
    solution.readInput();
    solution.processTask();
    std::cout << solution.getResult();
    return 0;
}

