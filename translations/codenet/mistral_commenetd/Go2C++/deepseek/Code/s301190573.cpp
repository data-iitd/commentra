#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int size = 1000000;

// Initialize reader
istream& reader = cin;

// Function to read a single line from the standard input
string NextLine() {
  string line;
  getline(reader, line);
  return line;
}

// Function to read two integers from a single line
pair<int, int> NextInts() {
  string line;
  getline(reader, line);
  stringstream ss(line);
  int x, y;
  ss >> x >> y;
  return make_pair(x, y);
}

// Function to read an array of integers from a single line
vector<int> NextIntArray() {
  string line;
  getline(reader, line);
  stringstream ss(line);
  vector<int> a;
  int num;
  while (ss >> num) {
    a.push_back(num - 1); // Decrease each index by 1 for some reason
  }
  return a;
}

// Initialize arrays for parent and rank
vector<int> par, rank;

// Function to initialize arrays
void initialize(int n) {
  par.resize(n);
  rank.resize(n);
  // Set all elements as their own parent initially
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}

// Function to find the root of a node
int root(int i) {
  // If the node is its own parent, return it
  if (par[i] == i) {
    return i;
  }
  // Recursively find the root of the parent
  par[i] = root(par[i]);
  // Return the new root
  return par[i];
}

// Function to check if two nodes have the same parent
bool same(int i, int j) {
  // Find the root of both nodes
  return root(i) == root(j);
}

// Function to unite two nodes
void unite(int i, int j) {
  // Find the roots of both nodes
  i = root(i);
  j = root(j);
  // If they already have the same parent, return
  if (i == j) {
    return;
  }
  // Make the smaller rank node a child of the larger rank node
  if (rank[i] < rank[j]) {
    par[i] = j;
  } else {
    par[j] = i;
    // If they have the same rank, increase the rank of the node with the smaller index
    if (rank[i] == rank[j]) {
      rank[i]++;
    }
  }
}

// Main function
int main() {
  // Read number of nodes and edges
  pair<int, int> nm = NextInts();
  int n = nm.first;
  int m = nm.second;
  // Read array of integers
  vector<int> p = NextIntArray();
  // Initialize arrays
  initialize(n);
  // Process each edge by uniting their parents
  for (int i = 0; i < m; i++) {
    pair<int, int> edge = NextInts();
    unite(edge.first - 1, edge.second - 1);
  }
  // Count the number of disconnected components
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (same(i, p[i])) {
      s++;
    }
  }
  // Print the result
  cout << s << endl;
  return 0;
}

