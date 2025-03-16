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
    void readInput();
    void processTask();
    std::string getResult() const;
};

void CodeforcesTask397BSolution::readInput() {
    std::cin >> t;
    std::cin.ignore();  // To ignore the newline character after the number of test cases
    for (int i = 0; i < t; ++i) {
        std::vector<int> query;
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int x;
        while (ss >> x) {
            query.push_back(x);
        }
        queries.push_back(query);
    }
}

void CodeforcesTask397BSolution::processTask() {
    std::vector<std::string> res;
    for (const auto& query : queries) {
        int k = query[0] / query[1];
        res.push_back(k * query[2] >= query[0] ? "Yes" : "No");
    }
    std::stringstream ss;
    for (const auto& r : res) {
        ss << r << "\n";
    }
    result = ss.str();
}

std::string CodeforcesTask397BSolution::getResult() const {
    return result;
}

int main() {
    CodeforcesTask397BSolution solution;
    solution.readInput();
    solution.processTask();
    std::cout << solution.getResult();
    return 0;
}

