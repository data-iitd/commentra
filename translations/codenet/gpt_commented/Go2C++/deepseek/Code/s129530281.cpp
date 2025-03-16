#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Segment {
public:
    int n, h, i, chunk;
    vector<int> unit;
    vector<vector<int>> bucket;

    void init(int n) {
        this->n = n;
        unit.push_back(1);
        bucket.push_back(vector<int>(n));

        chunk = 8;
        for (int i = 0; n > 1; ++i) {
            n = (n - 1) / chunk + 1;
            bucket.push_back(vector<int>(n));
            unit.push_back(unit[i] * chunk);
        }
        h = unit.size();
    }

    void maximize(int index, int value) {
        bucket[0][index] = value;
        for (i = 0; i < h - 1; ++i) {
            int s = index - index % chunk;
            int t = s + chunk;
            if (t > bucket[i].size()) {
                t = bucket[i].size();
            }
            int parent = index / chunk;
            int max = 0;
            for (int j = s; j < t; ++j) {
                if (max < bucket[i][j]) {
                    max = bucket[i][j];
                }
            }
            bucket[i + 1][parent] = max;
            index /= chunk;
        }
    }

    int top() {
        int index = 0;
        for (i = h - 2; i >= 0; --i) {
            int s = index * chunk;
            int t = s + chunk;
            if (t > bucket[i].size()) {
                t = bucket[i].size();
            }
            for (int j = s; j < t; ++j) {
                if (bucket[i][j] == bucket[i + 1][index]) {
                    index = j;
                    break;
                }
            }
        }
        return index;
    }
};

int main() {
    // Determine the input source: either standard input or a file specified as a command-line argument
    ifstream fp(argc > 1 ? argv[1] : "/dev/stdin");
    if (!fp) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize the scanner for the input source
    stringstream ss;
    ss << fp.rdbuf();
    string input = ss.str();
    istringstream iss(input);
    cin.rdbuf(iss.rdbuf());

    // Create a buffered writer for output
    ostream& writer = cout;

    // Read the number of elements and operations
    int n, m;
    cin >> n >> m;

    // Initialize the Segment structure
    Segment seg;
    seg.init(n);

    // Populate the segment with initial values
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        seg.maximize(i, value);
    }

    // Perform m operations to maximize the segment
    for (int i = 0; i < m; ++i) {
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
    }

    // Calculate the final answer by summing up the values in the first bucket
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += seg.bucket[0][i];
    }

    // Output the final result
    writer << ans << '\n';

    return 0;
}
