#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <string>
#include <sstream>

using namespace std;

// Function to read a single line of input from stdin
string input() {
    string line;
    getline(cin, line);
    return line;
}

// Function to convert a single input line to an integer
int INT() {
    return stoi(input());
}

// Function to read multiple integers from a single line of input
vector<int> MAP() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> result;
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

// Function to read a list of integers from a single line of input
vector<int> LIST() {
    return MAP();
}

// Function to read multiple lines of input and return them as a vector of strings
vector<string> ZIP(int n) {
    vector<string> result;
    for (int i = 0; i < n; ++i) {
        result.push_back(input());
    }
    return result;
}

// Setting the recursion limit to a higher value to avoid recursion errors
static const int RECURSION_LIMIT = 1000000;
void increase_recursion_limit() {
    const rlim_t stack_size = RECURSION_LIMIT;
    struct rlimit rl;
    int result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < stack_size) {
            rl.rlim_cur = stack_size;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) {
                cerr << "setrlimit returned result = " << result << endl;
            }
        }
    }
}

// Defining a constant for infinity
const int INF = INT_MAX;

// Defining a constant for modulo operation
const int MOD = 1000000007;

// Reading the number of balls (N) and the number of operations (M)
int N, M;
cin >> N >> M;
cin.ignore(); // To ignore the newline character after reading N and M

// Initializing the list of balls with pairs [white pieces, red pieces]
vector<pair<int, int>> balls(N, {1, 0});

// Special initialization for the first ball
balls[0] = {0, 1};

// Loop to process each operation
for (int i = 0; i < M; ++i) {
    vector<int> operation = MAP();
    int x = operation[0] - 1;
    int y = operation[1] - 1;
    
    // Swapping the balls if possible
    if (balls[x].first >= 1 && balls[x].second >= 1) {
        --balls[x].first;
        ++balls[y].second;
    } else if (balls[x].first == 0) {
        --balls[x].second;
        ++balls[y].second;
    } else {
        --balls[x].first;
        ++balls[y].first;
    }
}

// Counting the number of balls with at least one red or white piece
int ans = 0;
for (int i = 0; i < N; ++i) {
    if (balls[i].second) {
        ++ans;
    }
}

// Printing the final count
cout << ans << endl;

