
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

#define FOR(i, N) for (int i = 0; i < (int)N; i++) // Iterate through a range of numbers
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++) // Iterate through a range with a start and end
#define ALL(x) (x).begin(), (x).end() // Iterate through all elements of a container
#define MOD 1000000007 // Constants
#define MAX (1 << 29) // Constants
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__) // Debugging function

using Pi = pair<int, int>; // A pair of integers
using ll = long long; // A long long integer
const int INF = 1 << 28; // A constant integer

string to_string(string s) { // Convert a string to a string
  return s;
}

template <class S, class T>
string to_string(pair<S, T> p) { // Convert a pair to a string
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

template <class T>
string to_string(vector<T> v) { // Convert a vector to a string
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

void debug() { // Clear debug output
  cerr << endl;
}

template <class Head, class... Tail>
void debug(Head head, Tail... tail) { // Debug multiple variables
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() { // Print an empty line
  cout << endl;
}

template <class Head, class... Tail>
void print(Head head, Tail... tail) { // Print multiple variables
  cout << to_string(head);
  print(tail...);
}

void get() {} // Empty get function

template <class Head, class... Tail>
void get(Head& head, Tail&... tail) { // Get input for multiple variables
  cin >> head;
  get(tail...);
}

template <class T>
void getv(vector<T>& vec) { // Get input for a vector
  for (int i = 0; i < vec.size(); ++i)
    cin >> vec[i];
}

int main() {
  string S; // Declare a string variable named S
  cin >> S; // Get input for the string variable S

  if (S == "Sunny") { // Check if the string is equal to "Sunny"
    print("Cloudy"); // If true, print "Cloudy"
  } else if (S == "Cloudy") { // Check if the string is equal to "Cloudy"
    print("Rainy"); // If true, print "Rainy"
  } else { // If neither of the conditions are true
    print("Sunny"); // Print "Sunny"
  }

  return 0; // Return 0 to indicate successful execution
}