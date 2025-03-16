
#include <iostream>
#include <vector>
#include <string>

class CodeforcesTask397BSolution {
public:
    std::string solve(int t, std::vector<std::vector<int>> queries) {
        std::string result;
        for (const auto& query : queries) {
            int k = query[0] / query[1];
            result += (k * query[2] >= query[0]? "Yes\n" : "No\n");
        }
        return result;
    }
};

int main() {
    int t;
    std::cin >> t;
    std::vector<std::vector<int>> queries(t);
    for (auto& query : queries) {
        query.resize(3);
        std::cin >> query[0] >> query[1] >> query[2];
    }
    CodeforcesTask397BSolution solution;
    std::cout << solution.solve(t, queries) << std::endl;
    return 0;
}

Translate the above C++ code to Java and end with comment "