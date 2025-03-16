
#include <bits/stdc++.h>
using namespace std;

// The main package declaration.
// This package uses bufio and os for efficient I/O operations.

const int size = 1000000;
char buffer[size];
// Initializes a buffer with a specified size for efficient reading of standard input.

string NextLine() {
  gets(buffer);
  return string(buffer);
}
// Reads the next line of input from the standard input.

int NextInt() {
  int x;
  scanf("%d",&x);
  return x;
}
// Reads the next integer from the standard input.

vector<int> NextIntArray() {
  vector<int> a;
  int n;
  scanf("%d",&n);
  a.resize(n);
  for (int i=0;i<n;i++) {
    scanf("%d",&a[i]);
    a[i]--;
  }
  return a;
}
// Reads a line of space-separated integers, converts them to integers, and decrements each value by 1.

vector<int> par,rank;
// Global variables for the union-find data structure.

void initialize(int n) {
  par.resize(n);
  rank.resize(n);
  for (int i=0;i<n;i++) {
    par[i] = i;
  }
}
// Initializes the union-find data structure with n elements, each in its own set.

int root(int i) {
  if (par[i] == i) { return i; }
  return par[i] = root(par[i]);
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
  int n = NextInt();
  int m = NextInt();
  vector<int> p = NextIntArray();
  for (int i=0;i<m;i++) {
    int x = NextInt();
    int y = NextInt();
    unite(x-1,y-1);
  }
  int s = 0;
  for (int i=0;i<n;i++) {
    if (same(i,p[i])) { s++; }
  }
  printf("%d\n",s);
  return 0;
}
// The main function initializes the union-find data structure, processes the union operations, and counts the number of elements in the same connected component as their corresponding values in the array p.

