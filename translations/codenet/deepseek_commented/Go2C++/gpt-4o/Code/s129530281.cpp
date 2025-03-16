#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// Segment class represents a segment tree and includes methods to initialize it and update/query it.
class Segment {
public:
    int n, h, i, chunk;
    vector<int> unit;
    vector<vector<int>> bucket;

    // init initializes the segment tree with a given size n.
    void init(int n) {
        this->n = n;
        unit.push_back(1);
        bucket.push_back(vector<int>(n));

        chunk = 8;
        while (n > 1) {
            n = (n - 1) / chunk + 1;
            bucket.push_back(vector<int>(n));
            unit.push_back(unit.back() * chunk);
        }
        h = unit.size();
    }

    // maximize updates the value at a given index in the segment tree.
    void maximize(int index, int value) {
        bucket[0][index] = value;
        for (i = 0; i < h - 1; i++) {
            int s = index - index % chunk;
            int t = s + chunk;
            if (t > bucket[i].size()) {
                t = bucket[i].size();
            }
            int parent = index / chunk;
            int maxVal = 0;
            for (int j = s; j < t; j++) {
                maxVal = max(maxVal, bucket[i][j]);
            }
            bucket[i + 1][parent] = maxVal;
            index /= chunk;
        }
    }

    // top returns the index of the maximum value in the segment tree.
    int top() {
        int index = 0;
        for (i = h - 2; i >= 0; i--) {
            int s = index * chunk;
            int t = s + chunk;
            if (t > bucket[i].size()) {
                t = bucket[i].size();
            }
            for (int j = s; j < t; j++) {
                if (bucket[i][j] == bucket[i + 1][index]) {
                    index = j;
                    break;
                }
            }
        }
        return index;
    }
};

int main(int argc, char *argv[]) {
    ifstream inputFile;
    if (argc > 1) {
        inputFile.open(argv[1]);
    } else {
        inputFile.open("/dev/stdin");
    }
    istream &input = inputFile.is_open() ? inputFile : cin;

    // Read the number of elements (n) and the number of operations (m).
    int n, m;
    input >> n >> m;

    // Initialize the segment tree.
    Segment seg;
    seg.init(n);

    // Populate the segment tree with initial values.
    for (int i = 0; i < n; i++) {
        int value;
        input >> value;
        seg.maximize(i, value);
    }

    // Perform the specified number of operations on the segment tree.
    for (int i = 0; i < m; i++) {
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
    }

    // Calculate the sum of the values in the root bucket of the segment tree.
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.bucket[0][i];
    }

    // Write the result to the standard output.
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
