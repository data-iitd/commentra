#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

const int size = 1000000;
vector<int> par, rank;

// Function to read a line of input
string NextLine() {
    string line;
    getline(cin, line);
    return line;
}

// Function to read two integers from a single line of input
pair<int, int> NextInts() {
    string line = NextLine();
    istringstream iss(line);
    int x, y;
    iss >> x >> y;
    return {x, y};
}

// Function to read an array of integers from a single line of input
vector<int> NextIntArray() {
    string line = NextLine();
    istringstream iss(line);
    vector<int> a;
    int value;
    while (iss >> value) {
        a.push_back(value - 1); // Decrement each value by 1
    }
    return a;
}

// Function to initialize the union-find data structure
void initialize(int n) {
    par.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

// Function to find the root of the element i with path compression
int root(int i) {
    if (par[i] == i) return i;
    par[i] = root(par[i]);
    return par[i];
}

// Function to check if elements i and j are in the same set
bool same(int i, int j) {
    return root(i) == root(j);
}

// Function to unite the sets containing elements i and j
void unite(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        par[i] = j;
    } else {
        par[j] = i;
        if (rank[i] == rank[j]) rank[i]++;
    }
}

int main() {
    auto [n, m] = NextInts();
    vector<int> p = NextIntArray();
    int x, y;
    initialize(n);
    for (int i = 0; i < m; i++) {
        auto [x, y] = NextInts();
        unite(x - 1, y - 1);
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) s++;
    }
    cout << s << endl;
    return 0;
}

// <END-OF-CODE>
