
#include <bits/stdc++.h>
using namespace std;

// bufReader struct definition
// This struct is designed to efficiently read lines from standard input.
// It uses a buffer to minimize the number of system calls.
struct bufReader {
    istream& r;
    string buf;
    int i;
    bufReader(istream& r) : r(r), i(0) {}
    void readLine() {
        if (i < buf.size()) {
            return;
        }
        buf = "";
        i = 0;
        while (true) {
            string line;
            getline(r, line);
            buf += line;
            if (!r) {
                break;
            }
        }
    }
    string next() {
        readLine();
        int from = i;
        while (i < buf.size() && buf[i]!='') {
            i++;
        }
        string s = buf.substr(from, i - from);
        i++;
        return s;
    }
    string nextLine() {
        readLine();
        string s = buf.substr(i);
        i = buf.size();
        return s;
    }
};

// bufio Writer initialization
ostream& writer = cout;

// next wraps the reader.next() function.
string next() {
    return reader.next();
}

// nextInt reads the next token as an integer.
int64_t nextInt() {
    int64_t i;
    stringstream ss(next());
    ss >> i;
    return i;
}

// nextLine wraps the reader.nextLine() function.
string nextLine() {
    return reader.nextLine();
}

// out prints the arguments to the output with a newline.
void out(vector<string> a) {
    for (auto& x : a) {
        writer << x << " ";
    }
    writer << endl;
}

// max returns the maximum of two integers.
int64_t max(int64_t x, int64_t y) {
    if (x > y) {
        return x;
    }
    return y;
}

// min returns the minimum of two integers.
int64_t min(int64_t x, int64_t y) {
    if (x < y) {
        return x;
    }
    return y;
}

// joinInts joins an array of integers into a string with a separator.
string joinInts(vector<int64_t> a, string sep) {
    stringstream ss;
    for (int i = 0; i < a.size(); i++) {
        ss << a[i];
        if (i < a.size() - 1) {
            ss << sep;
        }
    }
    return ss.str();
}

// divUp returns the ceiling of the division of x by y.
int64_t divUp(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

// Main function
int main() {
    solve();
    writer.flush();
    return 0;
}

// Solve function
// Reads the number of elements N.
// Reads N pairs of integers T and A.
// Iteratively adjusts t and a to ensure the ratios are maintained.
// Outputs the sum of t and a after all adjustments.
void solve() {
    int64_t N = nextInt();
    vector<int64_t> T(N), A(N);
    for (int i = 0; i < N; i++) {
        T[i] = nextInt();
        A[i] = nextInt();
    }
    int64_t t = T[0], a = A[0];
    for (int i = 1; i < N; i++) {
        int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    out({to_string(t + a)});
}

The above C++ code is a translation of the given Go code. It uses the same framework and technology as the original code.