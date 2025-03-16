#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>

const int mod = 1e9 + 7;

// Function to read an integer from standard input.
int getInt() {
    int x;
    std::cin >> x;
    return x;
}

// Function to calculate the minimum sum of divisors of N.
int minDivisorSum(int N) {
    int sqrtN = static_cast<int>(std::sqrt(N));
    int minSum = N; // Initialize min with N.

    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) continue; // Check if i is a divisor of N.

        int num = i + (N / i) - 2; // Calculate the sum of the divisor and its complement.
        if (num < minSum) { // Update min if the current sum is smaller.
            minSum = num;
        }
    }

    return minSum;
}

// Graph class to represent a graph with n vertices and edges.
class Graph {
public:
    int n;
    std::vector<std::vector<int>> edges;

    Graph(int n) : n(n), edges(n) {}

    // Function to add an undirected edge between vertices u and v.
    void addEdge(int u, int v) {
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    // Depth-first search starting from vertex c.
    void dfs(int c, std::unordered_set<int>& visited) {
        visited.insert(c); // Mark the current vertex as visited.

        for (int v : edges[c]) {
            if (visited.find(v) != visited.end()) continue; // Skip if already visited.
            dfs(v, visited); // Recursively visit unvisited neighbors.
        }
    }
};

// Function to calculate the absolute value of a.
int abs(int a) {
    return std::abs(a);
}

// Function to calculate p raised to the power of q.
int pow(int p, int q) {
    return static_cast<int>(std::pow(p, q));
}

// Function to calculate n raised to the power of p modulo mod.
int powMod(int n, int p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return t * t % mod;
    } else {
        return n * powMod(n, p - 1) % mod;
    }
}

// Function to return the minimum value among the provided integers.
int min(int a, int b) {
    return std::min(a, b);
}

// Function to return the maximum value among the provided integers.
int max(int a, int b) {
    return std::max(a, b);
}

// Function to check if b is present in the vector a.
bool strSearch(const std::vector<std::string>& a, const std::string& b) {
    return std::find(a.begin(), a.end(), b) != a.end();
}

// Function to print the elements of an integer vector.
void printIntArray(const std::vector<int>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i];
        if (i < array.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

// Function to return x modulo mod.
int calcMod(int x) {
    return x % mod;
}

// Function to reverse a given string.
std::string reverse(const std::string& s) {
    return std::string(s.rbegin(), s.rend());
}

// Function to check if n is a prime number.
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

int main() {
    int N = getInt(); // Read the integer N from standard input.
    std::cout << minDivisorSum(N) << std::endl; // Print the minimum sum found.
    return 0;
}

// <END-OF-CODE>
