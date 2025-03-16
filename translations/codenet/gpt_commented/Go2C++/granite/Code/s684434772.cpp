
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Initialize a new scanner for reading input
    Scanner sc;

    // Read two integers n and k from input
    int n = sc.readInt();
    int k = sc.readInt();

    // Initialize a variable to hold the total count
    long long total = 0;

    // Calculate the total combinations from k to n+1
    for (int i = k; i <= n+1; i++) {
        total += combi(n, i); // Add combinations for the current i
        total = total % (pow(10, 9) + 7); // Apply modulo to prevent overflow
    }

    // Print the final total
    cout << total << endl;

    return 0;
}

// combi calculates the number of combinations based on the given n and k
long long combi(int n, int k) {
    // Calculate the minimum and maximum possible values for combinations
    long long min = (k-1) * k / 2;
    long long max = (2*n-k+1) * k / 2;
    // Return the count of combinations
    return max - min + 1;
}

// util
// *   math/simple

// Abs returns the absolute value of an integer
int Abs(int x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}

// Min returns the minimum value from a list of integers
int Min(vector<int> values) {
    if (values.empty()) {
        throw runtime_error("no values");
    }
    int min = values[0];
    for (int v : values) {
        if (v < min) {
            min = v;
        }
    }
    return min;
}

// Max returns the maximum value from a list of integers
int Max(vector<int> values) {
    if (values.empty()) {
        throw runtime_error("no values");
    }
    int max = values[0];
    for (int v : values) {
        if (v > max) {
            max = v;
        }
    }
    return max;
}

// Pow calculates the power of a base raised to an exponent
int Pow(int base, unsigned int exponent) {
    int answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

// Abs64 returns the absolute value of an int64
long long Abs64(long long x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}

// Min64 returns the minimum value from a list of int64 values
long long Min64(vector<long long> values) {
    if (values.empty()) {
        throw runtime_error("no values");
    }
    long long min = values[0];
    for (long long v : values) {
        if (v < min) {
            min = v;
        }
    }
    return min;
}

// Max64 returns the maximum value from a list of int64 values
long long Max64(vector<long long> values) {
    if (values.empty()) {
        throw runtime_error("no values");
    }
    long long max = values[0];
    for (long long v : values) {
        if (v > max) {
            max = v;
        }
    }
    return max;
}

// Pow64 calculates the power of a base (int64) raised to an exponent
long long Pow64(long long base, unsigned int exponent) {
    long long answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

// *   io

// Scanner is a custom input scanner that reads words from standard input
class Scanner {
public:
    Scanner() : bufScanner(new std::istream_iterator<std::string>(std::cin)), bufScannerEnd() {}

    string readString() {
        return *bufScanner++;
    }

    int readInt() {
        string text = readString();

        // Convert the scanned text to an integer
        int num;
        try {
            num = stoi(text);
        } catch (const invalid_argument& e) {
            throw runtime_error("invalid argument: " + string(e.what()));
        } catch (const out_of_range& e) {
            throw runtime_error("out of range: " + string(e.what()));
        }
        return num;
    }

    long long readInt64() {
        string text = readString();

        // Convert the scanned text to an int64
        long long num;
        try {
            num = stoll(text);
        } catch (const invalid_argument& e) {
            throw runtime_error("invalid argument: " + string(e.what()));
        } catch (const out_of_range& e) {
            throw runtime_error("out of range: " + string(e.what()));
        }
        return num;
    }

private:
    unique_ptr<std::istream_iterator<std::string>> bufScanner;
    std::istream_iterator<std::string> bufScannerEnd;
};

