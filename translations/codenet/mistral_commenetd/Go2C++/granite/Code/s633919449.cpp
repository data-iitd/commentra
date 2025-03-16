
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Constants for buffer sizes and modulo value
const int initialBufSize = 10000;
const int maxBufSize = 10000000;
const int mod = 1e9 + 7;

// Scanner for reading input
class Scanner {
private:
    istream& in;
    buf_size_t bufSize;
    char buf[maxBufSize];
    int bufLen;
    int bufPtr;

public:
    Scanner(istream& in, buf_size_t bufSize = initialBufSize) : in(in), bufSize(bufSize), bufLen(0), bufPtr(0) {}

    string next() {
        string res = "";
        while (bufLen == 0) {
            in.read(buf, bufSize);
            bufLen = in.gcount();
            bufPtr = 0;
        }

        while (bufPtr < bufLen && isspace(buf[bufPtr])) {
            bufPtr++;
        }

        while (bufPtr < bufLen &&!isspace(buf[bufPtr])) {
            res += buf[bufPtr++];
        }

        while (bufLen == bufPtr) {
            in.read(buf, bufSize);
            bufLen = in.gcount();
            bufPtr = 0;
        }

        return res;
    }

    string nextLine() {
        string res = "";
        while (bufLen == 0) {
            in.read(buf, bufSize);
            bufLen = in.gcount();
            bufPtr = 0;
        }

        while (bufPtr < bufLen && isspace(buf[bufPtr])) {
            bufPtr++;
        }

        while (bufPtr < bufLen &&!isspace(buf[bufPtr])) {
            res += buf[bufPtr++];
        }

        if (bufPtr < bufLen) {
            res += "\n";
            while (bufLen == bufPtr) {
                in.read(buf, bufSize);
                bufLen = in.gcount();
                bufPtr = 0;
            }
        }

        return res;
    }

    int nextInt() {
        int res = 0;
        char c = next()[0];
        bool negative = false;
        while (!isdigit(c)) {
            if (c == '-') {
                negative = true;
            }
            c = next()[0];
        }
        while (isdigit(c)) {
            res = 10 * res + (c - '0');
            c = next()[0];
        }

        return negative? -res : res;
    }
};

// Graph structure to represent edges
class Graph {
private:
    int n;
    vector<vector<int>> edges;

public:
    Graph(int n) : n(n), edges(n) {}

    void addEdge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    void dfs(int c, vector<bool>& visited) {
        visited[c] = true;
        for (int v : edges[c]) {
            if (!visited[v]) {
                dfs(v, visited);
            }
        }
    }

    void bfs(int c) {
        queue<int> q;
        q.push(c);
        vector<bool> visited(n, false);
        visited[c] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            // Process each adjacent node
            for (int v : edges[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

int main() {
    Scanner sc(cin);
    int N = sc.nextInt();

    // Determine the output based on the last digit of N
    switch (N % 10) {
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
            cout << "hon" << endl;
            break;
        case 0:
        case 1:
        case 6:
        case 8:
            cout << "pon" << endl;
            break;
        case 3:
            cout << "bon" << endl;
            break;
    }

    return 0;
}
