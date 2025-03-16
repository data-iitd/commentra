#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>

const int mod = 1e9 + 7;

int getInt() {
    int x;
    std::cin >> x;
    return x;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N = getInt();
    int sqrtN = static_cast<int>(std::sqrt(N));

    int minValue = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) {
            continue;
        }

        int num = i + (N / i) - 2;
        minValue = min(minValue, num);
    }

    std::cout << minValue << std::endl;
    return 0;
}

class Graph {
public:
    Graph(int n) : n(n), edges(n) {}

    void AddEdge(int u, int v) {
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    void dfs(int c, std::unordered_set<int>& visited) {
        visited.insert(c);
        for (int v : edges[c]) {
            if (visited.find(v) == visited.end()) {
                dfs(v, visited);
            }
        }
    }

private:
    int n;
    std::vector<std::vector<int>> edges;
};

int abs(int a) {
    return std::abs(a);
}

int pow(int p, int q) {
    return static_cast<int>(std::pow(p, q));
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return t * t % mod;
    } else {
        return n * powMod(n, p - 1) % mod;
    }
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrtN = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

std::string reverse(const std::string& s) {
    std::string reversed(s.rbegin(), s.rend());
    return reversed;
}

bool strSearch(const std::vector<std::string>& a, const std::string& b) {
    return std::find(a.begin(), a.end(), b) != a.end();
}

void printIntArray(const std::vector<int>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i];
        if (i < array.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int calcMod(int x) {
    return x % mod;
}

// <END-OF-CODE>
