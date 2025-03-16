#include <bits/stdc++.h>

using namespace std;

// Define a constant size for the buffered reader
const int size = 1000000;

// Create a buffered reader with the specified size
std::unique_ptr<std::streambuf> reader;

// Function to read the next line from standard input
std::string NextLine() {
  std::getline(std::cin, line); // Read a line from standard input
  return line; // Return the line
}

// Function to read two integers from the next line of input
std::pair<int, int> NextInts() {
  std::string s;
  std::getline(std::cin, s); // Read a line from standard input
  std::istringstream iss(s); // Create a string stream from the line
  int x, y;
  iss >> x >> y; // Read two integers from the line
  return {x, y}; // Return a pair of the two integers
}

// Function to read an array of integers from the next line of input
std::vector<int> NextIntArray() {
  std::string s;
  std::getline(std::cin, s); // Read a line from standard input
  std::istringstream iss(s); // Create a string stream from the line
  std::vector<int> a;
  int x;
  while (iss >> x) { // Read integers from the line
    a.push_back(x); // Append the integer to the array
  }
  return a; // Return the array
}

// Declare global variables for union-find structure
std::vector<int> par, rank;

int main() {
  // Read the number of elements (n) and number of unions (m)
  int n, m;
  std::tie(n, m) = NextInts();
  // Read the array of integers
  std::vector<int> p = NextIntArray();
  int x, y;
  
  // Initialize the union-find structure
  initialize(n);
  
  // Process each union operation
  for (int i = 0; i < m; i++) {
    std::tie(x, y) = NextInts(); // Read the pair of integers for union
    unite(x-1, y-1);   // Unite the two elements (convert to zero-based index)
  }
  
  // Count the number of elements that are in the same set as their corresponding value in p
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (same(i, p[i])) { // Check if the element is in the same set
      s++; // Increment the count
    }
  }
  
  // Print the result
  std::cout << s << std::endl;
}

// Function to initialize the union-find structure
void initialize(int n) {
  par = std::vector<int>(n); // Create parent array
  rank = std::vector<int>(n); // Create rank array
  
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

