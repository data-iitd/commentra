#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>

const int MOD = 1e9 + 7;

void printResult(int N) {
    switch (N % 10) {
        case 2: case 4: case 5: case 7: case 9:
            std::cout << "hon" << std::endl;
            break;
        case 0: case 1: case 6: case 8:
            std::cout << "pon" << std::endl;
            break;
        case 3:
            std::cout << "bon" << std::endl;
            break;
    }
}

class Graph {
public:
    int n;
    std::vector<std::vector<int>> edges;

    Graph(int n) : n(n), edges(n) {}

    void addEdge(int u, int v) {
        edges[v].push_back(u);
        edges[u].push_back(v);
    }
};

void dfs(int c, const std::vector<std::vector<int>>& edges, std::unordered_set<int>& visited) {
    visited.insert(c);
    for (int v : edges[c]) {
        if (visited.find(v) == visited.end()) {
            dfs(v, edges, visited);
        }
    }
}

void bfs(int c, const Graph& graph) {
    std::queue<int> next;
    next.push(c);
    std::unordered_set<int> visited;

    while (!next.empty()) {
        int u = next.front();
        next.pop();
        visited.insert(u);

        for (int v : graph.edges[u]) {
            if (visited.find(v) == visited.end()) {
                // Do something with v
                next.push(v);
            }
        }
    }
}

int getInt() {
    int x;
    std::cin >> x;
    return x;
}

std::vector<int> getIntArray(int n) {
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        array[i] = getInt();
    }
    return array;
}

std::string getString() {
    std::string s;
    std::cin >> s;
    return s;
}

std::vector<std::string> getStringArray(int n) {
    std::vector<std::string> array(n);
    for (int i = 0; i < n; i++) {
        array[i] = getString();
    }
    return array;
}

int abs(int a) {
    return std::abs(a);
}

int pow(int p, int q) {
    return static_cast<int>(std::pow(p, q));
}

int powMod(int n, int p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return t * t % MOD;
    } else {
        return n * powMod(n, p - 1) % MOD;
    }
}

int min(int a, int b) {
    return std::min(a, b);
}

int max(int a, int b) {
    return std::max(a, b);
}

bool strSearch(const std::vector<std::string>& a, const std::string& b) {
    return std::find(a.begin(), a.end(), b) != a.end();
}

void printIntArray(const std::vector<int>& array) {
    std::cout << "[";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i];
        if (i < array.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int calcMod(int x) {
    return x % MOD;
}

std::string reverse(const std::string& s) {
    return std::string(s.rbegin(), s.rend());
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

bool contains(const std::vector<int>& s, int e) {
    return std::find(s.begin(), s.end(), e) != s.end();
}

std::vector<int> makeRange(int min, int max) {
    std::vector<int> a(max - min + 1);
    std::iota(a.begin(), a.end(), min);
    return a;
}

std::vector<std::vector<int>> powerset2(const std::vector<int>& nums) {
    int length = static_cast<int>(std::pow(2, nums.size()));
    std::vector<std::vector<int>> result(length);

    result[0] = {};
    int index = 1;

    for (int n : nums) {
        int max = index;
        for (int i = 0; i < max; i++) {
            result[index] = result[i];
            result[index].push_back(n);
            index++;
        }
    }

    return result;
}

int calcGcd(int x, int y) {
    return y == 0 ? x : calcGcd(y, x % y);
}

std::vector<int> getDivisor(int n) {
    std::unordered_set<int> divisor;
    divisor.insert(1);
    if (n != 1) divisor.insert(n);

    int sqrtN = static_cast<int>(std::sqrt(n));
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            divisor.insert(i);
            divisor.insert(n / i);
        }
    }

    return std::vector<int>(divisor.begin(), divisor.end());
}

class IntHeap {
public:
    std::vector<int> heap;

    void push(int x) {
        heap.push_back(x);
        std::push_heap(heap.begin(), heap.end(), std::greater<int>());
    }

    int pop() {
        std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
        int value = heap.back();
        heap.pop_back();
        return value;
    }

    bool empty() const {
        return heap.empty();
    }
};

IntHeap initHeap() {
    return IntHeap();
}

int factMod(int n) {
    int value = 1;
    for (; n > 1; n--) {
        value = calcMod(value * n);
    }
    return value;
}

int combinationMod(int n, int k) {
    int factN = factMod(n);
    int factK = factMod(k);
    int factNK = factMod(n - k);
    int factKR = powMod(factK, MOD - 2);
    int factNKR = powMod(factNK, MOD - 2);
    return calcMod(factN * calcMod(factKR * factNKR));
}

std::vector<int> primeFactors(int n) {
    std::vector<int> factors;
    for (int i = 2; i * i <= n; ) {
        if (n % i == 0) {
            factors.push_back(i);
            n /= i;
        } else {
            i++;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    int N = getInt();
    printResult(N);
    return 0;
}

// <END-OF-CODE>
