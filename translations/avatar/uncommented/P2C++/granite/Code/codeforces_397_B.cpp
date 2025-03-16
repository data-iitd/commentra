
#include <iostream>
#include <vector>
#include <string>

class CodeforcesTask397BSolution {
public:
    std::string result;
    int t;
    std::vector < std::vector < int > > queries;
    void read_input() {
        std::cin >> t;
        for (int i = 0; i < t; i++) {
            std::vector < int > query;
            int a, b, c;
            std::cin >> a >> b >> c;
            query.push_back(a);
            query.push_back(b);
            query.push_back(c);
            queries.push_back(query);
        }
    }
    void process_task() {
        std::vector < std::string > res;
        for (std::vector < int > query : queries) {
            int k = query[0] / query[1];
            res.push_back(k * query[2] >= query[0]? "Yes" : "No");
        }
        for (std::string s : res) {
            result += s + "\n";
        }
    }
};

int main() {
    CodeforcesTask397BSolution solution;
    solution.read_input();
    solution.process_task();
    std::cout << solution.result;
    return 0;
}

