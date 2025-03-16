
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Constants for buffer sizes and modulo value
const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Scanner for reading input
class Scanner {
public:
    Scanner() {
        buf = new char[initialBufSize];
        bufSize = initialBufSize;
        bufPos = 0;
        bufEnd = 0;
    }

    int getInt() {
        int result = 0;
        char c = read();
        while (c < '0' || c > '9') {
            c = read();
        }
        while (c >= '0' && c <= '9') {
            result = result * 10 + c - '0';
            c = read();
        }
        return result;
    }

    string getString() {
        char c = read();
        while (c < 'a' || c > 'z') {
            c = read();
        }
        string result;
        while (c >= 'a' && c <= 'z') {
            result += c;
            c = read();
        }
        return result;
    }

private:
    char read() {
        if (bufPos == bufEnd) {
            bufPos = 0;
            bufEnd = fread(buf, 1, bufSize, stdin);
            if (bufEnd == 0) {
                return EOF;
            }
        }
        return buf[bufPos++];
    }

    char* buf;
    int bufSize;
    int bufPos;
    int bufEnd;
};

// Graph structure to represent a graph with n nodes
class Graph {
public:
    Graph(int n) {
        this->n = n;
        edges = new vector<int>[n];
    }

    void addEdge(int u, int v) {
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

private:
    int n;
    vector<int>* edges;
};

// Depth-first search (DFS) algorithm to traverse the graph
void dfs(int c, vector<int>* edges, map<int, int>* visited) {
    // Mark the current node as visited
    (*visited)[c] = 1;

    // Recursively visit all adjacent nodes
    for (int i = 0; i < edges[c].size(); i++) {
        int v = edges[c][i];
        if ((*visited)[v] == 1) {
            continue;
        }
        dfs(v, edges, visited);
    }
}

// Helper function to read an integer from input
int getInt() {
    return sc.getInt();
}

// Helper function to read a string from input
string getString() {
    return sc.getString();
}

// Function to return the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
    if (q == 0) {
        return 1;
    } else if (q % 2 == 0) {
        return pow(p, q / 2) * pow(p, q / 2);
    } else {
        return p * pow(p, q - 1);
    }
}

// Function to compute (n^p) % mod using exponentiation by squaring
int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % mod;
    } else {
        return (n * powMod(n, p - 1)) % mod;
    }
}

// Function to find the minimum value among a variable number of integers
int min(int nums, ...) {
    va_list args;
    va_start(args, nums);
    int result = va_arg(args, int);
    for (int i = 1; i < nums; i++) {
        int arg = va_arg(args, int);
        result = min(result, arg);
    }
    va_end(args);
    return result;
}

// Function to find the maximum value among a variable number of integers
int max(int nums, ...) {
    va_list args;
    va_start(args, nums);
    int result = va_arg(args, int);
    for (int i = 1; i < nums; i++) {
        int arg = va_arg(args, int);
        result = max(result, arg);
    }
    va_end(args);
    return result;
}

// Function to check if a string exists in a slice of strings
bool strSearch(vector<string> a, string b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b) {
            return true;
        }
    }
    return false;
}

// Function to print an integer array in a formatted way
void printIntArray(vector<int> array) {
    string strArray = "";
    for (int i = 0; i < array.size(); i++) {
        strArray += to_string(array[i]);
        if (i < array.size() - 1) {
            strArray += " ";
        }
    }
    cout << strArray << endl;
}

// Function to calculate x % mod
int calcMod(int x) {
    return x % mod;
}

// Function to reverse a string
string reverse(string s) {
    string result = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        result += s[i];
    }
    return result;
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    // Check for factors from 3 to the square root of n
    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // Read an integer N from input
    int N = getInt();
    // Calculate the integer square root of N
    int sqrtN = sqrt(N);

    // Initialize min to N, which will hold the minimum value found
    int min = N;
    // Iterate through all possible divisors of N
    for (int i = 1; i <= sqrtN; i++) {
        // If i is not a divisor of N, skip to the next iteration
        if (N % i != 0) {
            continue;
        }

        // Calculate the value based on the divisor and its complement
        int num = i + (N / i) - 2;
        // Update min if the new value is smaller
        if (num < min) {
            min = num;
        }
    }

    // Print the minimum value found
    cout << min << endl;
    return 0;
}

