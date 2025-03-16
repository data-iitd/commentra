
#include <bits/stdc++.h>
using namespace std;

// getScanner initializes a new scanner that reads from the given file pointer.
FILE* getScanner(FILE* fp) {
    setvbuf(fp, NULL, _IOFBF, 500000);
    return fp;
}

// getNextString reads the next word from the scanner.
string getNextString(FILE* scanner) {
    char buf[1000001];
    fscanf(scanner, "%s", buf);
    return string(buf);
}

// getNextInt converts the next word to an integer.
int getNextInt(FILE* scanner) {
    int i;
    fscanf(scanner, "%d", &i);
    return i;
}

// getNextInt64 converts the next word to a 64-bit integer.
long long getNextInt64(FILE* scanner) {
    long long i;
    fscanf(scanner, "%lld", &i);
    return i;
}

// getNextUint64 converts the next word to an unsigned 64-bit integer.
unsigned long long getNextUint64(FILE* scanner) {
    unsigned long long i;
    fscanf(scanner, "%llu", &i);
    return i;
}

// getNextFloat64 converts the next word to a floating-point number.
double getNextFloat64(FILE* scanner) {
    double i;
    fscanf(scanner, "%lf", &i);
    return i;
}

// Main function handles file input, initializes a segment tree, and processes the input to compute an answer.
int main() {
    FILE* fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }
    FILE* scanner = getScanner(fp);
    FILE* writer = stdout;

    // Read the number of elements (n) and the number of operations (m).
    int n = getNextInt(scanner);
    int m = getNextInt(scanner);

    // Initialize the segment tree.
    vector<vector<int>> seg(1);
    seg[0].resize(n);

    // Populate the segment tree with initial values.
    for (int i = 0; i < n; i++) {
        seg[0][i] = getNextInt(scanner);
    }

    // Perform the specified number of operations on the segment tree.
    for (int i = 0; i < m; i++) {
        seg[0][max_element(seg[0].begin(), seg[0].end()) - seg[0].begin()] /= 2;
    }

    // Calculate the sum of the values in the root bucket of the segment tree.
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg[0][i];
    }

    // Write the result to the standard output.
    fprintf(writer, "%lld\n", ans);
    fflush(writer);
}

// Segment struct represents a segment tree and includes methods to initialize it and update/query it.
struct Segment {
    int n, h, i, chunk;
    vector<int> unit;
    vector<vector<int>> bucket;

    void init(int n) {
        this->n = n;
        unit.resize(1);
        unit[0] = 1;
        bucket.resize(1);
        bucket[0].resize(n);

        chunk = 8;
        for (int i = 0; n > 1; i++) {
            n = (n-1)/chunk + 1;
            bucket.resize(i+1);
            bucket[i+1].resize(n);
            unit.resize(i+1);
            unit[i+1] = unit[i]*chunk;
        }
        h = unit.size();
    }

    void maximize(int index, int value) {
        bucket[0][index] = value;
        for (i = 0; i < h-1; i++) {
            int s = index - index%chunk;
            int t = s + chunk;
            if (t > bucket[i].size()) {
                t = bucket[i].size();
            }
            int parent = index / chunk;
            int max = 0;
            for (int j = s; j < t; j++) {
                if (max < bucket[i][j]) {
                    max = bucket[i][j];
                }
            }
            bucket[i+1][parent] = max;
            index /= chunk;
        }
    }

    int top() {
        int index = 0;
        for (i = h - 2; i >= 0; i--) {
            int s = index * chunk;
            int t = s + chunk;
            if (t > bucket[i].size()) {
                t = bucket[i].size();
            }
            for (int j = s; j < t; j++) {
                if (bucket[i][j] == bucket[i+1][index]) {
                    index = j;
                    break;
                }
            }
        }

        return index;
    }
};

// Translate the above C++ code to Java and end with comment "