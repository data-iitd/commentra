
```cpp
#include <bits/stdc++.h>
using namespace std;

// Define bufReader struct to handle buffered reading from standard input
struct bufReader {
    istream *r;
    vector<char> buf;
    int i;

    bufReader(istream& _r) : r(&_r), i(0) {}

    void readLine() {
        if (i < buf.size()) {
            return; // Return if there are still bytes to read
        }
        buf.clear(); // Reset buffer
        i = 0; // Reset index
        for (char c; *r >> noskipws >> c; ) {
            if (c == '\n') {
                break; // Break if the line is not a prefix
            }
            buf.push_back(c); // Append line to buffer
        }
    }

    string next() {
        readLine(); // Ensure the buffer is filled
        int from = i; // Store the starting index
        for (; i < buf.size(); i++) {
            if (buf[i] =='') { // Stop at space
                break;
            }
        }
        string s = string(buf.begin() + from, buf.begin() + i); // Extract the token
        i++; // Move index forward
        return s;
    }

    string nextLine() {
        readLine(); // Ensure the buffer is filled
        string s = string(buf.begin() + i, buf.end()); // Get the remaining line
        i = buf.size(); // Move index to the end of buffer
        return s;
    }
};

// Initialize a global bufReader instance for reading input
bufReader reader(cin);

// next is a helper function to read the next token
string next() {
    return reader.next();
}

// nextInt reads the next token as an int
int nextInt() {
    int i;
    cin >> i;
    return i;
}

// nextLine is a helper function to read the next full line
string nextLine() {
    return reader.nextLine();
}

// out writes the output to the standard output
void out(const vector<string>& a) {
    copy(a.begin(), a.end(), ostream_iterator<string>(cout, "\n"));
}

// max returns the maximum of two int values
int max(int x, int y) {
    return x > y? x : y; // Return x if it's greater, otherwise return y
}

// min returns the minimum of two int values
int min(int x, int y) {
    return x < y? x : y; // Return x if it's lesser, otherwise return y
}

// abs returns the absolute value of an int
int abs(int x) {
    return x < 0? -x : x; // Return negation if x is negative, otherwise return x
}

// join joins a slice of strings into a single string with a separator
string join(const vector<string>& a, const string& sep) {
    ostringstream s; // Create an output string stream
    copy(a.begin(), a.end(), ostream_iterator<string>(s, sep)); // Join the strings with the separator
    return s.str(); // Return the joined string
}

// divUp performs ceiling division on two int values
int divUp(int x, int y) {
    return (x + y - 1) / y; // Ceiling division
}

// gcd computes the greatest common divisor of two int values
int gcd(int x, int y) {
    if (x < y) {
        swap(x, y); // Ensure x is the larger value
    }
    for (; y!= 0; swap(x, y)) {
        x %= y; // Euclidean algorithm
    }
    return x; // Return GCD
}

// lcm computes the least common multiple of two int values
int lcm(int x, int y) {
    return x * y / gcd(x, y); // LCM using GCD
}

// pow computes x raised to the power of y for int values
int pow(int x, int y) {
    int r = 1;
    for (; y > 0; y >>= 1) {
        if (y & 1) {
            r *= x; // Multiply r by x if y is odd
        }
        x *= x; // Square x if y is even
    }
    return r; // Return the result
}

int main() {
    int N, _;
    cin >> N >> _; // Read number of elements and ignore the second value
    vector<int> A(N); // Create a vector to hold the elements
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // Read each element into the vector
    }
    int maxProfit = 0; // Initialize maximum profit
    int maxCnt = 0; // Initialize count of maximum profit occurrences
    int maxA = A[N - 1]; // Start with the last element as the maximum
    for (int i = N - 2; i >= 0; i--) { // Iterate backwards through the vector
        int profit = max(0, maxA - A[i]); // Calculate profit based on the current element
        if (maxProfit < profit) { // If we found a new maximum profit
            maxProfit = profit; // Update maximum profit
            maxCnt = 1; // Reset count to 1
        } else if (maxProfit == profit) { // If we found another occurrence of the maximum profit
            maxCnt++; // Increment the count
        }
        maxA = max(maxA, A[i]); // Update the maximum element seen so far
    }
    cout << maxCnt << endl; // Output the count of maximum profit occurrences
    return 0;
}

