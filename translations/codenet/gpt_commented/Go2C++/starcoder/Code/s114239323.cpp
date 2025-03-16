#include <bits/stdc++.h>

using namespace std;

int main() {
    // Read the number of elements
    int N = nextInt();
    // Read the heights into a slice
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        h[i] = nextInt();
    }

    // Initialize a dynamic programming slice to store minimum costs
    vector<int> dp(N);
    for (int i = 0; i < N; i++) {
        dp[i] = 0; // Set initial values to zero
    }
    
    // Base case: cost to jump from the first to the second height
    dp[1] = abs(h[0] - h[1]);

    // Fill the dp slice with minimum costs for each position
    for (int i = 2; i < N; i++) {
        dp[i] = min({
            dp[i-1] + abs(h[i] - h[i-1]), // Cost from the previous height
            dp[i-2] + abs(h[i] - h[i-2]), // Cost from two heights back
        });
    }

    // Output the minimum cost to reach the last height
    cout << dp[N-1] << endl;
}

/* templates */

// Max function returns the maximum value from a slice of integers
int Max(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Min function returns the minimum value from a slice of integers
int Min(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Sum function calculates the sum of a slice of integers
int Sum(vector<int> a) {
    int r = 0;
    for (int i = 0; i < a.size(); i++) {
        r += a[i];
    }
    return r;
}

// Abs function returns the absolute value of an integer
int Abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Pair struct represents a pair of integers
struct Pair {
    int a, b;
};

// Pairs is a slice of Pair
typedef vector<Pair> Pairs;

// Len returns the length of the Pairs slice
int Len(Pairs p) {
    return p.size();
}

// Swap exchanges the elements at indices i and j in the Pairs slice
void Swap(Pairs &p, int i, int j) {
    Pair t = p[i];
    p[i] = p[j];
    p[j] = t;
}

// Less compares two pairs based on the second element of the pair
bool Less(Pair p, Pair q) {
    return p.b < q.b;
}

// nextReader is a function that reads input from standard input
std::function<string()> nextReader = []() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    return [&]() {
        string s;
        getline(cin, s);
        return s;
    };
}();

// nextString reads the next string from input
string nextString() {
    return nextReader();
}

// nextInt64 reads the next int64 from input
int64_t nextInt64() {
    int64_t v;
    cin >> v;
    return v;
}

// nextInt reads the next int from input
int nextInt() {
    int v;
    cin >> v;
    return v;
}

// nextInts reads n integers from input and returns them as a slice
vector<int> nextInts(int n) {
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = nextInt();
    }
    return r;
}

// nextStrings reads n strings from input and returns them as a slice
vector<string> nextStrings(int n) {
    vector<string> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = nextString();
    }
    return r;
}

// nextFloat64 reads the next float64 from input
double nextFloat64() {
    double v;
    cin >> v;
    return v;
}

