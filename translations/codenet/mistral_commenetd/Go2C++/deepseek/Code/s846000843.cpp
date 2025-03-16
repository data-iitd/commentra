#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>

class Io {
public:
    Io() : reader(std::cin), writer(std::cout) {}
    void Flush() { writer.flush(); }
    std::string NextLine() {
        std::string line;
        std::getline(reader, line);
        return line;
    }
    std::string Next() {
        while (tokens.empty()) {
            std::string line = NextLine();
            std::istringstream iss(line);
            std::string token;
            while (iss >> token) {
                tokens.push_back(token);
            }
        }
        std::string token = tokens.front();
        tokens.pop_front();
        return token;
    }
    int Int() { return std::stoi(Next()); }
    void PrintLn(const std::vector<int>& a) {
        for (int i : a) {
            writer << i << " ";
        }
        writer << "\n";
    }
    void PrintLn(const std::vector<std::string>& a) {
        for (const std::string& s : a) {
            writer << s << " ";
        }
        writer << "\n";
    }
private:
    std::istream& reader;
    std::ostream& writer;
    std::deque<std::string> tokens;
};

int abs(int a) { return a >= 0 ? a : -a; }
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

std::vector<int> CumSum(const std::vector<int>& nums) {
    std::vector<int> sums(1, 0);
    for (int num : nums) {
        sums.push_back(sums.back() + num);
    }
    return sums;
}

int main() {
    Io io;

    int n = io.Int();
    std::vector<int> aa(n);
    for (int i = 0; i < n; ++i) {
        aa[i] = io.Int();
    }

    std::vector<int> cumsum = CumSum(aa);
    int ans = 2020202020;

    for (int i = 1; i < cumsum.size() - 1; ++i) {
        int diff1 = abs(cumsum.back() - cumsum[i]);
        int diff2 = cumsum[i] - cumsum[0];
        ans = min(ans, min(diff1, diff2));
    }

    std::cout << ans << "\n";
    io.Flush();
    return 0;
}
