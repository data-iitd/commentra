#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

// Helper function to read a line from standard input
std::string readLine() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

// Helper function to split a string into tokens
std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Helper function to convert a string to an integer
int toInt(const std::string &s) {
    return std::stoi(s);
}

// Helper function to convert a string to a long long integer
long long toInt64(const std::string &s) {
    return std::stoll(s);
}

// Helper function to output results
void out(const std::vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

void solve() {
    std::vector<std::string> input = split(readLine(), ' ');
    int N = toInt(input[0]);
    int _ = toInt(input[1]); // Ignore the second value

    std::vector<int> A(N);
    input = split(readLine(), ' ');
    for (int i = 0; i < N; ++i) {
        A[i] = toInt(input[i]);
    }

    int maxProfit = 0;
    int maxCnt = 0;
    int maxA = A[N - 1];

    for (int i = N - 2; i >= 0; --i) {
        int profit = std::max(0, maxA - A[i]);
        if (maxProfit < profit) {
            maxProfit = profit;
            maxCnt = 1;
        } else if (maxProfit == profit) {
            ++maxCnt;
        }
        maxA = std::max(maxA, A[i]);
    }

    std::cout << maxCnt << std::endl;
}

int main() {
    solve();
    return 0;
}
