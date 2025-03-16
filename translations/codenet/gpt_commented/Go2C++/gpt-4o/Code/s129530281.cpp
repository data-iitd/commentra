#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// Segment structure to hold the segment data and operations
class Segment {
public:
    int n, h, i, chunk;
    vector<int> unit;
    vector<vector<int>> bucket;

    // Initialize the segment structure with the given size n.
    void init(int n) {
        this->n = n;
        unit.push_back(1); // Initialize unit array
        bucket.push_back(vector<int>(n)); // Initialize bucket array

        chunk = 8; // Define the chunk size
        while (n > 1) {
            n = (n - 1) / chunk + 1; // Reduce n based on the chunk size
            bucket.push_back(vector<int>(n)); // Append a new bucket
            unit.push_back(unit[i] * chunk); // Update unit array
        }
        h = unit.size(); // Set the height of the segment
    }

    // Update the segment at a given index with a new value.
    void maximize(int index, int value) {
        bucket[0][index] = value; // Set the value in the first bucket
        for (i = 0; i < h - 1; i++) {
            int s = index - index % chunk; // Calculate the start of the current chunk
            int t = s + chunk; // Calculate the end of the current chunk
            if (t > bucket[i].size()) {
                t = bucket[i].size(); // Adjust end if it exceeds the bucket length
            }
            int parent = index / chunk; // Determine the parent index
            int maxVal = 0; // Initialize max value
            for (int j = s; j < t; j++) {
                maxVal = max(maxVal, bucket[i][j]); // Find the maximum value in the current chunk
            }
            bucket[i + 1][parent] = maxVal; // Update the parent bucket with the maximum value
            index /= chunk; // Move to the parent index for the next iteration
        }
    }

    // Retrieve the index of the top value in the segment.
    int top() {
        int index = 0; // Start from the root index
        for (i = h - 2; i >= 0; i--) {
            int s = index * chunk; // Calculate the start of the current chunk
            int t = s + chunk; // Calculate the end of the current chunk
            if (t > bucket[i].size()) {
                t = bucket[i].size(); // Adjust end if it exceeds the bucket length
            }
            for (int j = s; j < t; j++) {
                if (bucket[i][j] == bucket[i + 1][index]) {
                    index = j; // Update index if the value matches the top value
                    break;
                }
            }
        }
        return index; // Return the index of the top value
    }
};

// Function to read integers from input
int getNextInt(istringstream &iss) {
    int value;
    iss >> value;
    return value;
}

int main(int argc, char *argv[]) {
    // Determine the input source: either standard input or a file specified as a command-line argument
    ifstream file;
    if (argc > 1) {
        file.open(argv[1]); // Open the file if an argument is provided
    }
    istream &input = (argc > 1) ? file : cin; // Use file or standard input
    istringstream iss;
    string line;

    // Read the number of elements and operations
    getline(input, line);
    iss.clear();
    iss.str(line);
    int n = getNextInt(iss);
    int m = getNextInt(iss);

    // Initialize the Segment structure
    Segment seg;
    seg.init(n); // Initialize the segment with size n

    // Populate the segment with initial values
    getline(input, line);
    iss.clear();
    iss.str(line);
    for (int i = 0; i < n; i++) {
        seg.maximize(i, getNextInt(iss)); // Maximize the segment with the input values
    }

    // Perform m operations to maximize the segment
    for (int i = 0; i < m; i++) {
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1); // Maximize using the top value and half of the last bucket's first element
    }

    // Calculate the final answer by summing up the values in the first bucket
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.bucket[0][i]; // Accumulate the values
    }

    // Output the final result
    cout << ans << endl;

    if (argc > 1) {
        file.close(); // Close the file if it was opened
    }

    return 0;
}

// <END-OF-CODE>
