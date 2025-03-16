
#include <bits/stdc++.h>

using namespace std;

const int size = 1000000;

// Initialize reader
std::istream_iterator<char> input_iterator;
std::istream_iterator<char> eos;
std::istringstream stream;

// Function to read a single line from the standard input
std::string NextLine() {
  stream.clear();
  stream.seekg(0, ios::end);
  stream << std::cin.rdbuf();
  std::string line = stream.str();
  stream.clear();
  stream.str(std::string());
  return line;
}

// Function to read two integers from a single line
std::pair<int, int> NextInts() {
  std::string line = NextLine();
  std::vector<std::string> s = split(line);
  int x = std::stoi(s[0]);
  int y = std::stoi(s[1]);
  return std::make_pair(x, y);
}

// Function to read an array of integers from a single line
std::vector<int> NextIntArray() {
  std::string line = NextLine();
  std::vector<std::string> s = split(line);
  std::vector<int> a(s.size());
  for (int i = 0; i < s.size(); i++) {
    a[i] = std::stoi(s[i]);
  }
  return a;
}

// Function to split a string
std::vector<std::string> split(const std::string &s) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  while (std::getline(tokenStream, token,'')) {
    tokens.push_back(token);
  }
  return tokens;
}

// Initialize arrays for parent and rank
std::vector<int> par, rank;

// Function to initialize arrays
void initialize(int n) {
  par = std::vector<int>(n);
  rank = std::vector<int>(n);
  // Set all elements as their own parent initially
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}

// Main function
int main() {
  // Read number of nodes and edges
  int n, m;
  std::tie(n, m) = NextInts();
  // Read array of edges
  std::vector<int> p = NextIntArray();
  // Initialize arrays
  initialize(n);
  // Process each edge by uniting their parents
  for (int i = 0; i < m; i++) {
    int x, y;
    std::tie(x, y) = NextInts();
    unite(x-1, y-1);
  }
  // Count the number of disconnected components
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (same(i, p[i])) {
      s++;
    }
  }
  // Print the result
  std::cout << s << std::endl;
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

