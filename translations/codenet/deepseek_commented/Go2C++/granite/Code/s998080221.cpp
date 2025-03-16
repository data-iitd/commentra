

#include <bits/stdc++.h>

using namespace std;

// bufReader is a struct to efficiently read input.
struct bufReader {
    istream *r;
    string buf;
    int i;

    bufReader(istream *r) : r(r), i(0) {}

    void readLine() {
        if (i < buf.size()) {
            return;
        }
        buf = "";
        i = 0;
        while (true) {
            string line;
            getline(*r, line);
            buf += line;
            if (!r->good()) {
                break;
            }
            if (line.back()!= '\n') {
                continue;
            }
            break;
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

// Initialize global reader and writer for input and output operations.
bufReader reader(cin);
ostream writer(cout);

// next is a wrapper for reader.next().
string next() {
    return reader.next();
}

// nextInt64 reads the next token as an int64.
int64_t nextInt64() {
    int64_t i;
    *reader.r >> i;
    return i;
}

// nextInt reads the next token as an int.
int nextInt() {
    return int(nextInt64());
}

// nextLine is a wrapper for reader.nextLine().
string nextLine() {
    return reader.nextLine();
}

// out prints the arguments to the output.
void out(const initializer_list<string>& a) {
    bool first = true;
    for (const auto& s : a) {
        if (!first) {
            writer << " ";
        }
        writer << s;
        first = false;
    }
    writer << endl;
}

// max64 returns the maximum of two int64 values.
int64_t max64(int64_t x, int64_t y) {
    if (x > y) {
        return x;
    }
    return y;
}

// max returns the maximum of two int values.
int max(int x, int y) {
    return int(max64(int64_t(x), int64_t(y)));
}

// min64 returns the minimum of two int64 values.
int64_t min64(int64_t x, int64_t y) {
    if (x < y) {
        return x;
    }
    return y;
}

// min returns the minimum of two int values.
int min(int x, int y) {
    return int(min64(int64_t(x), int64_t(y)));
}

// abs64 returns the absolute value of an int64.
int64_t abs64(int64_t x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

// abs returns the absolute value of an int.
int abs(int x) {
    return int(abs64(int64_t(x)));
}

// joinInt64s joins an array of int64 values into a string with a separator.
string joinInt64s(const vector<int64_t>& a, const string& sep) {
    vector<string> b;
    for (int64_t v : a) {
        b.push_back(to_string(v));
    }
    return join(b, sep);
}

// joinInts joins an array of int values into a string with a separator.
string joinInts(const vector<int>& a, const string& sep) {
    vector<string> b;
    for (int v : a) {
        b.push_back(to_string(v));
    }
    return join(b, sep);
}

// divUp64 returns the ceiling of the division of x by y.
int64_t divUp64(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

// divUp returns the ceiling of the division of x by y.
int divUp(int x, int y) {
    return int(divUp64(int64_t(x), int64_t(y)));
}

// gcd64 returns the greatest common divisor of two int64 values.
int64_t gcd64(int64_t x, int64_t y) {
    if (x < y) {
        swap(x, y);
    }
    while (y!= 0) {
        int64_t t = x % y;
        x = y;
        y = t;
    }
    return x;
}

// gcd returns the greatest common divisor of two int values.
int gcd(int x, int y) {
    return int(gcd64(int64_t(x), int64_t(y)));
}

// lcm64 returns the least common multiple of two int64 values.
int64_t lcm64(int64_t x, int64_t y) {
    return x * y / gcd64(x, y);
}

// lcm returns the least common multiple of two int values.
int lcm(int x, int y) {
    return int(lcm64(int64_t(x), int64_t(y)));
}

// pow64 returns the result of raising x to the power of y.
int64_t pow64(int64_t x, int64_t y) {
    return int64_t(pow(double(x), double(y)));
}

// pow returns the result of raising x to the power of y.
int pow(int x, int y) {
    return int(pow64(int64_t(x), int64_t(y)));
}

// main function calls solve and flushes the writer at the end.
int main() {
    int N, _;
    cin >> N >> _;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int maxProfit = 0;
    int maxCnt = 0;
    int maxA = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        int profit = max(0, maxA - A[i]);
        if (maxProfit < profit) {
            maxProfit = profit;
            maxCnt = 1;
        } else if (maxProfit == profit) {
            maxCnt++;
        }
        maxA = max(maxA, A[i]);
    }
    out(maxCnt);
}

