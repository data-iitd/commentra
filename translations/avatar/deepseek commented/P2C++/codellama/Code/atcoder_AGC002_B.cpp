
#include <bits/stdc++.h>
using namespace std;

// Function to read a single line of input from stdin
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to convert a single input line to an integer
int INT() {
    return stoi(input());
}

// Function to read multiple integers from a single line of input
vector<int> MAP() {
    string s = input();
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            v.push_back(s[i] - '0');
        }
    }
    return v;
}

// Function to read a list of integers from a single line of input
vector<int> LIST() {
    string s = input();
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            v.push_back(s[i] - '0');
        }
    }
    return v;
}

// Function to read multiple lines of input and return them as a list of tuples
vector<vector<int>> ZIP(int n) {
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back(MAP());
    }
    return v;
}

// Setting the recursion limit to a higher value to avoid recursion errors
void set_recursion_limit(int n) {
    stack_limit::set_limit(n);
}

// Defining a constant for infinity
const int INF = 1e9 + 7;

// Defining a constant for modulo operation
const int mod = 1e9 + 7;

// Reading the number of balls (N) and the number of operations (M)
int N, M;
cin >> N >> M;

// Initializing the list of balls with pairs [white pieces, red pieces]
vector<vector<int>> balls(N, vector<int>(2, 0));

// Special initialization for the first ball
balls[0][1] = 1;

// Loop to process each operation
for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    int w_x = balls[x - 1][0];
    int r_x = balls[x - 1][1];
    int w_y = balls[y - 1][0];
    int r_y = balls[y - 1][1];
    
    // Swapping the balls if possible
    if (w_x >= 1 && r_x >= 1) {
        balls[x - 1][0] -= 1;
        balls[y - 1][1] += 1;
    } else if (w_x == 0) {
        balls[x - 1][1] -= 1;
        balls[y - 1][1] += 1;
    } else {
        balls[x - 1][0] -= 1;
        balls[y - 1][0] += 1;
    }
}

// Counting the number of balls with at least one red or white piece
int ans = 0;
for (int i = 0; i < N; i++) {
    if (balls[i][1]) {
        ans += 1;
    }
}

// Printing the final count
cout << ans << endl;

