
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

const int size = 1000000;
// Initializes a buffered reader with a specified size for efficient reading of standard input.

vector<int> par,rank;
// Global variables for the union-find data structure.

int root(int i) {
  if (par[i] == i) { return i; }
  par[i] = root(par[i]);
  return par[i];
}
// Finds the root of the element i, applying path compression to improve future queries.

bool same(int i,int j) {
  return root(i) == root(j);
}
// Checks if the elements i and j are in the same set.

void unite(int i,int j) {
  i = root(i);
  j = root(j);
  if (i == j) { return; }
  if (rank[i] < rank[j]) {
    par[i] = j;
  } else {
    par[j] = i;
    if (rank[i] == rank[j]) { rank[i]++; }
  }
}
// Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i=0;i<n;i++) {
    cin >> p[i];
    p[i]--;
  }
  initialize(n);
  for (int i=0;i<m;i++) {
    int x,y;
    cin >> x >> y;
    unite(x-1,y-1);
  }
  int s = 0;
  for (int i=0;i<n;i++) {
    if (same(i,p[i])) { s++; }
  }
  cout << s << endl;
  return 0;
}
// The main function initializes the union-find data structure, processes the union operations, and counts the number of elements in the same connected component as their corresponding values in the array p.

void initialize(int n) {
  par = vector<int>(n);
  rank = vector<int>(n);
  for (int i=0;i<n;i++) {
    par[i] = i;
  }
}
// Initializes the union-find data structure with n elements, each in its own set.

