#include <bits/stdc++.h>
using namespace std;

// Function to read a line of input and strip whitespace
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read an integer from input
int INT() {
    return stoi(input());
}

// Function to read a list of integers from input
vector<int> MAP() {
    vector<int> v;
    string s = input();
    stringstream ss(s);
    int x;
    while (ss >> x) {
        v.push_back(x);
        if (ss.peek() == ',') ss.ignore();
    }
    return v;
}

// Function to read a list of integers and return it as a list
vector<int> LIST() {
    return MAP();
}

// Function to read multiple lists of integers and return them as zipped tuples
auto ZIP(int n) {
    return map(vector<int>(n), [](int &x) { return LIST(); });
}

// Set the recursion limit to a high value to allow deep recursion
const int N = 100000;
const int M = 100000;
const int INF = 1000000000;
const int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> balls(N, vector<int>(2, 0));
    balls[0][0] = 0;
    balls[0][1] = 1;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int w_x = balls[x][0];
        int r_x = balls[x][1];
        int w_y = balls[y][0];
        int r_y = balls[y][1];

        if (w_x >= 1 && r_x >= 1) {
            balls[x][0] -= 1;
            balls[y][1] += 1;
        } else if (w_x == 0) {
            balls[x][1] -= 1;
            balls[y][1] += 1;
        } else {
            balls[x][0] -= 1;
            balls[y][0] += 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i][1]) ans++;
    }

    cout << ans << "\n";
}

