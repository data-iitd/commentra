
```cpp
#include <bits/stdc++.h>
using namespace std;

// Constants for buffer sizes and modulo value
const int initialBufSize = 10000;
const int maxBufSize = 10000000;
const int mod = 1e9 + 7;

// Scanner for reading input
class Scanner {
public:
    Scanner() {
        buf = new char[initialBufSize];
        bs = new streambuf();
        is = new istream(bs);
        cin.rdbuf(bs);
    }

    ~Scanner() {
        delete[] buf;
        delete bs;
        delete is;
    }

    string next() {
        cin.getline(buf, maxBufSize);
        return string(buf);
    }

    int nextInt() {
        int x;
        *is >> x;
        return x;
    }

private:
    char* buf;
    streambuf* bs;
    istream* is;
};

// Main function
int main() {
    Scanner sc;
    int N = sc.nextInt();
    int sqrtN = sqrt(N);
    int min = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i!= 0) {
            continue;
        }
        int num = i + (N / i) - 2;
        if (num < min) {
            min = num;
        }
    }
    cout << min << endl;
    return 0;
}

