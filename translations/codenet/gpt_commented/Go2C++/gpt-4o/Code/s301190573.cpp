#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to read the next line from standard input
string NextLine() {
    string line;
    getline(cin, line);
    return line;
}

// Function to read two integers from the next line of input
pair<int, int> NextInts() {
    string line = NextLine();
    istringstream iss(line);
    int x, y;
    iss >> x >> y;
    return {x, y}; // Return the two integers as a pair
}

// Function to read an array of integers from the next line of input
vector<int> NextIntArray() {
    string line = NextLine();
    istringstream iss(line);
    vector<int> a;
    int value;
    while (iss >> value) {
        a.push_back(value - 1); // Decrement to convert to zero-based index
    }
    return a; // Return the integer array
}

// Declare global variables for union-find structure
vector<int> par, rank;

void initialize(int n) {
    par.resize(n); // Create parent array
    rank.resize(n); // Create rank array
    
    // Set each element's parent to itself
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

// Function to find the root of the element with path compression
int root(int i) {
    if (par[i] == i) {
        return i; // Return the root if it is its own parent
    }
    par[i] = root(par[i]); // Path compression
    return par[i]; // Return the root
}

// Function to check if two elements are in the same set
bool same(int i, int j) {
    return root(i) == root(j); // Check if their roots are the same
}

// Function to unite two elements into the same set
void unite(int i, int j) {
    i = root(i); // Find the root of the first element
    j = root(j); // Find the root of the second element
    
    if (i == j) {
        return; // If they are already in the same set, do nothing
    }
    
    // Union by rank
    if (rank[i] < rank[j]) {
        par[i] = j; // Make j the parent of i
    } else {
        par[j] = i; // Make i the parent of j
        if (rank[i] == rank[j]) {
            rank[i]++; // Increment rank if they were the same
        }
    }
}

int main() {
    // Read the number of elements (n) and number of unions (m)
    auto [n, m] = NextInts();
    // Read the array of integers
    vector<int> p = NextIntArray();
    int x, y;
    
    // Initialize the union-find structure
    initialize(n);
    
    // Process each union operation
    for (int i = 0; i < m; i++) {
        auto [x, y] = NextInts(); // Read the pair of integers for union
        unite(x - 1, y - 1);      // Unite the two elements (convert to zero-based index)
    }
    
    // Count the number of elements that are in the same set as their corresponding value in p
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) { // Check if the element is in the same set
            s++; // Increment the count
        }
    }
    
    // Print the result
    cout << s << endl;
    return 0;
}

// <END-OF-CODE>
