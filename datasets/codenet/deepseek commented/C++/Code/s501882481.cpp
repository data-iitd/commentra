#include <algorithm>  // For standard algorithms like sort, find, etc.
#include <cmath>      // For mathematical functions like pow, sqrt, etc.
#include <cstdio>     // For C-style input/output operations.
#include <iostream>   // For C++ style input/output operations.
#include <map>        // For associative arrays (key-value pairs).
#include <numeric>    // For numeric operations like accumulate.
#include <queue>      // For queue data structure.
#include <set>        // For set data structure.
#include <sstream>    // For string stream operations.
#include <stack>      // For stack data structure.
#include <string>     // For string operations.
#include <unordered_set> // For unordered set data structure.
#include <vector>     // For vector data structure.

using namespace std;  // To avoid prefixing standard library names with 'std::'.

#define FOR(i, N) for (int i = 0; i < (int)N; i++)  // Loop from 0 to N-1.
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)  // Loop from a to b-1.
#define ALL(x) (x).begin(), (x).end()  // Get all elements of a container.
#define MOD 1000000007  // Define a constant modulo value.
#define MAX (1 << 29)  // Define a maximum value.
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)  // Debug macro for logging.

using Pi = pair<int, int>;  // Define a type alias for a pair of integers.
using ll = long long;  // Define a type alias for a long long integer.
const int INF = 1 << 28;  // Define a constant for infinity.

// Utility function to convert a string to a string representation.
string to_string(string s) {
  return s;
}

// Utility function to convert a pair to a string representation.
template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

// Utility function to convert a vector to a string representation.
template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

// Debug function to print a newline.
void debug() {
  cerr << endl;
}

// Debug function to print debug information with a line number.
template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

// Print function to print a newline.
void print() {
  cout << endl;
}

// Print function to print multiple items.
template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

// Utility function to read a single item.
void get() {}

// Utility function to read multiple items.
template <class Head, class... Tail>
void get(Head& head, Tail&... tail) {
  cin >> head;
  get(tail...);
}

// Utility function to read a vector of items.
template <class T>
void getv(vector<T>& vec) {
  for (int i = 0; i < vec.size(); ++i)
    cin >> vec[i];
}

// Main function to execute the program.
int main() {
  string S;
  cin >> S;
  if (S == "Sunny") {
    print("Cloudy");
  } else if (S == "Cloudy") {
    print("Rainy");
  } else {
    print("Sunny");
  }
  return 0;
}
