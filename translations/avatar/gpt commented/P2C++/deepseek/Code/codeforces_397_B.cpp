#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class CodeforcesTask397BSolution {
public:
    void read_input();
    void process_task();
    std::string get_result() const;

private:
    std::string result;
    int t;
    std::vector<std::vector<int>> queries;
};

void CodeforcesTask397BSolution::read_input() {
    std::cin >> t;
    queries.resize(t);
    for (int i = 0; i < t; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        queries[i] = {a, b, c};
    }
}

void CodeforcesTask397BSolution::process_task() {
    std::vector<std::string> res;
    for (const auto& query : queries) {
        int k = query[0] / query[1];
        res.push_back(k * query[2] >= query[0] ? "Yes" : "No");
    }
    std::ostringstream oss;
    for (const auto& r : res) {
        oss << r << "\n";
    }
    result = oss.str();
}

std::string CodeforcesTask397BSolution::get_result() const {
    return result;
}

int main() {
    CodeforcesTask397BSolution solution;
    solution.read_input();
    solution.process_task();
    std::cout << solution.get_result();
    return 0;
}

