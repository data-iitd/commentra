#include <algorithm>  # For standard algorithms like sort, find, etc.
#include <cmath>      # For mathematical functions like pow, sqrt, etc.
#include <cstdio>     # For C-style input/output operations.
#include <iostream>   # For C++ style input/output operations.
#include <map>        # For associative arrays (key-value pairs).
#include <numeric>    # For numeric operations like accumulate.
#include <queue>      # For queue data structure.
#include <set>        # For set data structure.
#include <sstream>    # For string stream operations.
#include <stack>      # For stack data structure.
#include <string>     # For string operations.
#include <unordered_set> # For unordered set data structure.
#include <vector>     # For vector data structure.

using namespace std;  # To avoid prefixing standard library names with 'std::'.

#define FOR(i, N) for (int i = 0; i < (int)N; i++)  # Loop from 0 to N-1.
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)  # Loop from a to b-1.
#define ALL(x) (x).begin(), (x).end()  # Get all elements of a container.
#define MOD 1000000007  # Define a constant modulo value.
#define MAX (1 << 29)  # Define a maximum value.
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)  # Debug macro for logging.

using Pi = pair<int, int>;  # Define a type alias for a pair of integers.
using ll = long long;  # Define a type alias for a long long integer.
const int INF = 1 << 28;  # Define a constant for infinity.

# Utility function to convert a string to a string representation.
def to_string(s):
    return s

# Utility function to convert a pair to a string representation.
def to_string(p):
    return "{" + to_string(p.first) + "," + to_string(p.second) + "}"

# Utility function to convert a vector to a string representation.
def to_string(v):
    ret = "{"
    for i in range(v.size() - 1):
        ret += to_string(v[i]) + ","
    if v.size() > 0:
        ret += to_string(v.back())
    ret += "}"
    return ret

# Debug function to print a newline.
def debug():
    print()

# Debug function to print debug information with a line number.
def debug(head, *tail):
    print(to_string(head), end=" ")
    debug(*tail)

# Print function to print a newline.
def print():
    print()

# Print function to print multiple items.
def print(head, *tail):
    print(to_string(head), end=" ")
    print(*tail)

# Utility function to read a single item.
def get():
    pass

# Utility function to read multiple items.
def get(head, *tail):
    head = input()
    get(*tail)

# Utility function to read a vector of items.
def getv(vec):
    for i in range(vec.size()):
        vec[i] = input()

# Main function to execute the program.
def main():
    S = input()
    if S == "Sunny":
        print("Cloudy")
    elif S == "Cloudy":
        print("Rainy")
    else:
        print("Sunny")
    return 0


if __name__ == "__main__":
    main()

