// Include necessary headers
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

// Using standard namespace
using namespace std;

// Segment class represents a segment tree data structure
class Segment {
public:
    int n, h, i, chunk;
    vector<int> unit;
    vector<vector<int>> bucket;

    // init function initializes the Segment struct with the given size n
    void init(int n) {
        this->n = n;
        unit.push_back(1);
        bucket.push_back(vector<int>(n));

        // Calculate the chunk size for the segment tree
        int chunk = 8;
        while (n > 1) {
            n = (n - 1) / chunk + 1;
            bucket.push_back(vector<int>(n));
            unit.push_back(unit.back() * chunk);
        }
        h = unit.size();
        this->chunk = chunk;
    }

    // maximize function updates the segment tree with the given index and value
    void maximize(int index, int value) {
        // Update the leaf node with the given index and value
        bucket[0][index] = value;

        // Propagate the update to the parent nodes
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

    // top function returns the index of the maximum value in the current segment
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

// Function to read integers from input
int getNextInt(istringstream &iss) {
    int value;
    iss >> value;
    return value;
}

// Main function is the entry point of the program
int main(int argc, char *argv[]) {
    // Open the standard input file if a command-line argument is provided
    ifstream fp;
    if (argc > 1) {
        fp.open(argv[1]);
    } else {
        fp.open("/dev/stdin");
    }

    // Initialize a Segment instance
    Segment seg;
    string line;
    getline(fp, line);
    istringstream iss(line);
    
    // Read the first two integers from the input
    int n = getNextInt(iss);
    int m = getNextInt(iss);
    
    // Initialize the Segment struct with the given size n
    seg.init(n);

    // Process the input data by maximizing the segments
    for (int i = 0; i < n; i++) {
        getline(fp, line);
        istringstream issValue(line);
        seg.maximize(i, getNextInt(issValue));
    }
    for (int i = 0; i < m; i++) {
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
    }

    // Calculate the answer
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.bucket[0][i];
    }

    // Print the answer to the output
    cout << ans << endl;

    // Close the file if it was opened
    if (fp.is_open()) {
        fp.close();
    }

    return 0;
}

// <END-OF-CODE>
