#include <bits/stdc++.h>
using namespace std;

// I/O
#define READ_FROM_FILE "input.txt"
#define WRITE_TO_FILE "output.txt"
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// General purpose
#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 (int64_t)1 << 60
#define INF_INT32 (int32_t)1 << 30
#define NIL -1

// for dijkstra, prim, and so on
#define WHITE 0
#define GRAY 1
#define BLACK 2

// Read
template <typename T>
T read() {
    T t;
    cin >> t;
    return t;
}

template <typename T>
vector<T> read_vector(int n) {
    vector<T> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    return v;
}

// Utilities
template <typename T>
void print_vector(const vector<T>& v, char delimiter=' ') {
    if (v.empty()) {
        cout << endl;
        return;
    }
    for (int i = 0; i < v.size(); ++i) { cout << v[i] << (i < v.size() - 1 ? delimiter : '\n'); }
}

template <typename T>
void print_array(const T a[], int n, char delimiter=' ') {
    if (n <= 0) {
        cout << endl;
        return;
    }
    for (int i = 0; i < n; ++i) { cout << a[i] << (i < n - 1 ? delimiter : '\n'); }
}

template <typename T>
void fill_vector(vector<T>& v, int n, T elem) {
    v.resize(n, elem);
}

template <typename T>
void fill_array(T a[], int n, T elem) {
    for (int i = 0; i < n; ++i) {
        a[i] = elem;
    }
}

// Main
int main() {
    FAST_IO
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    vector<vector<int>> patterns;
    function<void(vector<int>&, int)> generate_patterns = [&](vector<int>& current, int depth) {
        if (depth == k) {
            patterns.push_back(current);
            return;
        }
        for (int i = 0; i < 4; ++i) {
            current.push_back(i);
            generate_patterns(current, depth + 1);
            current.pop_back();
        }
    };

    vector<int> initial;
    generate_patterns(initial, 0);

    for (const auto& P : patterns) {
        int r = a, g = b, bl = c;
        for (int i = 0; i < k; ++i) {
            if (P[i] == 1) r *= 2;
            else if (P[i] == 2) g *= 2;
            else if (P[i] == 3) bl *= 2;
        }
        if (g > r && bl > g) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
