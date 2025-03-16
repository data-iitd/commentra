
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

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

    int getIntArray(int n) {
        int *array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = getInt();
        }
        return array;
    }

    string getString() {
        char c = read();
        while (c < 'a' || c > 'z') {
            c = read();
        }
        string result = "";
        while (c >= 'a' && c <= 'z') {
            result += c;
            c = read();
        }
        return result;
    }

    string getStringArray(int n) {
        string *array = new string[n];
        for (int i = 0; i < n; i++) {
            array[i] = getString();
        }
        return array;
    }

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

private:
    char *buf;
    int bufSize;
    int bufPos;
    int bufEnd;
};

// Graph structure to represent edges
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

    int n;
    vector<int> *edges;
};

// Depth-first search (DFS) algorithm implementation
void dfs(int c, vector<int> *edges, map<int, int> &visited) {
    visited[c] = 1;

    // Visit all adjacent nodes recursively
    for (int i = 0; i < edges[c].size(); i++) {
        int v = edges[c][i];
        if (visited[v]) {
            continue;
        }
        dfs(v, edges, visited);
    }
}

// Breadth-first search (BFS) algorithm implementation
void bfs(int c, Graph *graph) {
    queue<int> next;
    next.push(c);
    map<int, int> visited;

    // Continue until there are no more nodes to visit
    while (!next.empty()) {
        int u = next.front();
        next.pop();
        visited[u] = 1;

        // Process each adjacent node
        for (int i = 0; i < graph->edges[u].size(); i++) {
            int v = graph->edges[u][i];
            if (visited[v]) {
                continue;
            }

            // Placeholder for processing the node (e.g., marking, counting, etc.)

            next.push(v);
        }
    }
}

// Function to read an integer from input
int getInt() {
    return sc.getInt();
}

// Function to read an array of integers from input
int *getIntArray(int n) {
    return sc.getIntArray(n);
}

// Function to read a string from input
string getString() {
    return sc.getString();
}

// Function to read an array of strings from input
string *getStringArray(int n) {
    return sc.getStringArray(n);
}

// Function to calculate the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}

// Function to calculate p raised to the power of q
int pow(int p, int q) {
    if (q == 0) {
        return 1;
    } else if (q % 2 == 0) {
        return pow(p, q / 2) * pow(p, q / 2);
    } else {
        return p * pow(p, q - 1);
    }
}

// Function to calculate n raised to the power of p modulo mod
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

// Function to find the minimum value among a list of integers
int min(int nums[], int n) {
    int res = nums[0];
    for (int i = 1; i < n; i++) {
        res = min(res, nums[i]);
    }
    return res;
}

// Function to find the maximum value among a list of integers
int max(int nums[], int n) {
    int res = nums[0];
    for (int i = 1; i < n; i++) {
        res = max(res, nums[i]);
    }
    return res;
}

// Function to check if a string exists in an array of strings
bool strSearch(string a[], string b) {
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        if (a[i] == b) {
            return true;
        }
    }
    return false;
}

// Function to print an array of integers
void printIntArray(int array[], int n) {
    string strArray = "";
    for (int i = 0; i < n; i++) {
        strArray += to_string(array[i]) + " ";
    }
    cout << strArray.substr(0, strArray.size() - 1) << endl;
}

// Function to calculate x modulo mod
int calcMod(int x) {
    return x % mod;
}

// Function to reverse a string
string reverse(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
    return s;
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

    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to check if an integer exists in a slice
bool contains(int s[], int n, int e) {
    for (int i = 0; i < n; i++) {
        if (s[i] == e) {
            return true;
        }
    }
    return false;
}

// Function to create a range of integers from min to max
int *makeRange(int min, int max) {
    int *a = new int[max - min + 1];
    for (int i = 0; i < max - min + 1; i++) {
        a[i] = min + i;
    }
    return a;
}

// Function to generate the powerset of a given slice of integers
vector<vector<int>> powerset2(int nums[]) {
    int length = pow(2, sizeof(nums) / sizeof(nums[0]));
    vector<vector<int>> result(length);

    int index = 0;
    result[index] = vector<int>();
    index++;

    // Generate all subsets
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        int max = index;
        for (int j = 0; j < max; j++) {
            result[index] = result[j];
            result[index].push_back(nums[i]);
            index++;
        }
    }

    return result;
}

// Function to calculate the greatest common divisor (GCD) of two integers
int calcGcd(int x, int y) {
    if (y == 0) {
        return x;
    } else if (x >= y) {
        return calcGcd(y, x % y);
    } else {
        return calcGcd(x, y % x);
    }
}

// Function to get all divisors of a number
vector<int> getDivisor(int n) {
    map<int, int> divisor;
    divisor[1] = 1;
    if (n != 1) {
        divisor[n] = 1;
    }

    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            divisor[i] = 1;
            divisor[n / i] = 1;
        }
    }

    vector<int> divisorArray;
    for (auto d : divisor) {
        divisorArray.push_back(d.first);
    }
    return divisorArray;
}

// Custom heap type for integers
class IntHeap {
public:
    IntHeap() {
        heap = new vector<int>();
    }

    void pushHeap(int n) {
        heap->push_back(n);
        int i = heap->size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if ((*heap)[p] < (*heap)[i]) {
                swap((*heap)[p], (*heap)[i]);
                i = p;
            } else {
                break;
            }
        }
    }

    int popHeap() {
        int result = (*heap)[0];
        (*heap)[0] = (*heap)[heap->size() - 1];
        heap->pop_back();
        int i = 0;
        while (i * 2 + 1 < heap->size()) {
            int l = i * 2 + 1;
            int r = i * 2 + 2;
            int largest = l;
            if (r < heap->size() && (*heap)[l] < (*heap)[r]) {
                largest = r;
            }
            if ((*heap)[i] < (*heap)[largest]) {
                swap((*heap)[i], (*heap)[largest]);
                i = largest;
            } else {
                break;
            }
        }
        return result;
    }

private:
    vector<int> *heap;
};

// Initialize a new integer heap
IntHeap *initHeap() {
    IntHeap *ih = new IntHeap();
    return ih;
}

// Function to calculate factorial modulo mod
int factMod(int n) {
    int value = 1;
    for (; n > 1; n--) {
        value = (value * n) % mod;
    }
    return value;
}

// Function to calculate combinations modulo mod
int combinationMod(int n, int k) {
    int factN = factMod(n);
    int factK = factMod(k);
    int factNK = factMod(n - k);
    int factKR = powMod(factK, mod - 2);
    int factNKR = powMod(factNK, mod - 2);
    return (factN * (factKR * factNKR)) % mod;
}

// Function to find prime factors of a number
vector<int> primeFactors(int n) {
    vector<int> factors;
    int i = 2;
    for (; i * i <= n; i++) {
        int r = n % i;
        if (r == 0) {
            n /= i;
            factors.push_back(i);
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    // Read an integer input
    int N = getInt();

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

