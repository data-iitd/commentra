
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <stack>
#include <queue>
#include <ctime>
#include <valarray>
#include <cassert>
#include <numeric>
#include <functional>
#include <iomanip>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define IFOR(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define FOREACH(it, arr) for (typeof((arr).begin()) it = (arr).begin(); it!= (arr).end(); it++)
#define fill(a, v) memset(a, v, sizeof a)
#define size(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define head first
#define tail second
#define let const auto

template <typename T, typename U> inline void chmin(T &x, U y) { if (y < x) x = y; }
template <typename T, typename U> inline void chmax(T &x, U y) { if (x < y) x = y; }

inline void init() { cin.tie(0); cout.tie(0); std::ios::sync_with_stdio(false); cout << fixed << setprecision(10); }

const int MOD = 1000000007;
const double EPS = 1e-10;
const double PI = acos(-1.0);

// Define a constant size for the buffered reader
const int size = 1000000;

// Create a buffered reader with the specified size
char buffer[size];
int pos = size;

// Function to read the next line from standard input
string NextLine() {
  string s;
  while (true) {
    char c = getchar();
    if (c == '\n') break;
    s += c;
  }
  return s;
}

// Function to read two integers from the next line of input
int NextInt() {
  int x;
  scanf("%d", &x);
  return x;
}

// Function to read an array of integers from the next line of input
vector<int> NextIntArray() {
  string s = NextLine();
  stringstream ss(s);
  vector<int> a;
  int x;
  while (ss >> x) {
    a.push_back(x);
  }
  return a;
}

// Declare global variables for union-find structure
vector<int> par, rank;

int main() {
  // Read the number of elements (n) and number of unions (m)
  int n = NextInt();
  int m = NextInt();
  // Read the array of integers
  vector<int> p = NextIntArray();
  int x, y;
  
  // Initialize the union-find structure
  initialize(n);
  
  // Process each union operation
  REP(i, m) {
    x = NextInt();
    y = NextInt();
    unite(x - 1, y - 1); // Unite the two elements (convert to zero-based index)
  }
  
  // Count the number of elements that are in the same set as their corresponding value in p
  int s = 0;
  REP(i, n) {
    if (same(i, p[i])) { // Check if the element is in the same set
      s++; // Increment the count
    }
  }
  
  // Print the result
  cout << s << endl;
  
  return 0;
}

// Function to initialize the union-find structure
void initialize(int n) {
  par.resize(n); // Create parent array
  rank.resize(n); // Create rank array
  
  // Set each element's parent to itself
  REP(i, n) {
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