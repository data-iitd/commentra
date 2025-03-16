
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure for sorting pairs
struct pair {
    int64_t index;
    int64_t p1, p2;
};
typedef vector<pair> pairs;

// Implement sort.Interface for pairs
bool operator<(const pair& a, const pair& b) {
    return a.index < b.index;
}

// Define a structure for sorting int64 slices
struct Int64Slice {
    vector<int64_t> data;

    Int64Slice(const vector<int64_t>& data) : data(data) {}

    int size() const {
        return data.size();
    }

    int64_t operator[](int i) const {
        return data[i];
    }

    bool operator<(const Int64Slice& other) const {
        return data < other.data;
    }
};

// Constants for buffer sizes and infinity value
const int initialBufSize = 1e4;
const int maxBufSize = 1e8;
const int64_t INF = 1e8;

// Global variables for input/output handling and direction vectors
vector<int64_t> di = {-1, 0, 1, 0}; // Direction vectors for row movement
vector<int64_t> dj = {0, -1, 0, 1}; // Direction vectors for column movement

int main() {
    // Set up the scanner buffer and read three integers A, B, C
    vector<char> buf(initialBufSize);
    cin.rdbuf()->pubsetbuf(&buf[0], maxBufSize);
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int64_t A, B, C;
    cin >> A >> B >> C;

    // Check if C is within the range [A, B] and print the result
    if (C >= A && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

