
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

const int size = 1000000;
string NextLine() {
  string line,buffer;
  bool isPrefix = true;
  while (isPrefix) {
    getline(cin,line);
    buffer += line;
    isPrefix = cin.good();
  }
  return buffer;
}
pair<int,int> NextInts() {
  string s = NextLine();
  istringstream iss(s);
  int x,y;
  iss >> x >> y;
  return make_pair(x,y);
}
vector<int> NextIntArray() {
  string s = NextLine();
  istringstream iss(s);
  vector<int> a;
  int t;
  while (iss >> t) {
    a.push_back(t-1);
  }
  return a;
}

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> p = NextIntArray();
  vector<int> par(n),rank(n);
  for (int i=0;i<n;i++) {
    par[i] = i;
  }
  for (int i=0;i<m;i++) {
    int x,y;
    tie(x,y) = NextInts();
    unite(x-1,y-1);
  }
  int s = 0;
  for (int i=0;i<n;i++) {
    if (same(i,p[i])) { s++; }
  }
  cout << s << endl;
  return 0;
}

void initialize(int n) {
  par.resize(n);
  rank.resize(n);
  for (int i=0;i<n;i++) {
    par[i] = i;
  }
}
int root(int i) {
  if (par[i] == i) { return i; }
  par[i] = root(par[i]);
  return par[i];
}
bool same(int i,int j) {
  return root(i) == root(j);
}
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

