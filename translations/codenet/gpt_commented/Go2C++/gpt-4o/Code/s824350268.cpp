#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

// Constants for modulo value
const int mod = 1e9 + 7;

// Function to read an integer from input
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Function to calculate x % mod
int calcMod(int x) {
    return x % mod;
}

// Function to find the minimum value among a variable number of integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the maximum value among a variable number of integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to reverse a string
string reverse(const string &s) {
    string reversed(s.rbegin(), s.rend());
    return reversed;
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrtN = static_cast<int>(sqrt(n));
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Main function
int main() {
    // Read an integer N from input
    int N = getInt();
    // Calculate the integer square root of N
    int sqrtN = static_cast<int>(sqrt(N));

    // Initialize min to N, which will hold the minimum value found
    int minValue = N;
    // Iterate through all possible divisors of N
    for (int i = 1; i <= sqrtN; i++) {
        // If i is not a divisor of N, skip to the next iteration
        if (N % i != 0) {
            continue;
        }

        // Calculate the value based on the divisor and its complement
        int num = i + (N / i) - 2;
        // Update min if the new value is smaller
        minValue = min(minValue, num);
    }

    // Print the minimum value found
    cout << minValue << endl;

    return 0;
}

// Graph structure to represent a graph with n nodes
class Graph {
public:
    int n;
    vector<vector<int>> edges;

    // Constructor to create a new graph with n nodes
    Graph(int n) : n(n), edges(n) {}

    // Add an undirected edge between nodes u and v
    void addEdge(int u, int v) {
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    // Depth-first search (DFS) algorithm to traverse the graph
    void dfs(int c, unordered_set<int> &visited) {
        // Mark the current node as visited
        visited.insert(c);

        // Recursively visit all adjacent nodes
        for (int v : edges[c]) {
            if (visited.find(v) != visited.end()) {
                continue;
            }
            dfs(v, visited);
        }
    }
};

// <END-OF-CODE>
