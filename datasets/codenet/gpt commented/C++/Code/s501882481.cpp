#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Macro definitions for convenience in loops and other operations
#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define MAX (1 << 29)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

// Type definitions for ease of use
using Pi = pair<int, int>;
using ll = long long;
const int INF = 1 << 28;

// Function to convert a string to string (identity function)
string to_string(string s) {
  return s;
}

// Template function to convert a pair to string representation
template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

// Template function to convert a vector to string representation
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

// Function to print a new line for debugging purposes
void debug() {
  cerr << endl;
}

// Template function to print multiple values for debugging
template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

// Function to print a new line
void print() {
  cout << endl;
}

// Template function to print multiple values to standard output
template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

// Function to handle no input (base case for variadic template)
void get() {}

// Template function to read multiple values from standard input
template <class Head, class... Tail>
void get(Head& head, Tail&... tail) {
  cin >> head;
  get(tail...);
}

// Template function to read values into a vector from standard input
template <class T>
void getv(vector<T>& vec) {
  for (int i = 0; i < vec.size(); ++i)
    cin >> vec[i];
}

// Main function where the program execution begins
int main() {
  string S; // Variable to store the input weather condition
  cin >> S; // Read the weather condition from standard input

  // Determine the next weather condition based on the current one
  if (S == "Sunny") {
    print("Cloudy"); // If it's sunny, print "Cloudy"
  } else if (S == "Cloudy") {
    print("Rainy"); // If it's cloudy, print "Rainy"
  } else {
    print("Sunny"); // If it's neither, it must be rainy, print "Sunny"
  }

  return 0; // Return 0 to indicate successful execution
}
