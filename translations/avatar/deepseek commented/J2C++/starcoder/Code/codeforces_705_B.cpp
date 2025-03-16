#include <bits/stdc++.h>
using namespace std;

class FastReader {
    std::istream *stream;
    std::string buf, cur;
    int pos;
    FastReader() : stream(&std::cin), buf(), cur(), pos(0) {}
    char getChar() {
        if (pos == buf.size()) {
            pos = 0, buf.clear();
            std::getline(*stream, buf);
        }
        return buf[pos++];
    }
    bool isSpace(char c) {
        return c =='' || c == '\n' || c == '\r' || c == '\t';
    }
    void read(int &x) {
        x = 0;
        bool neg = 0;
        char c;
        while (isSpace(c = getChar()))
            ;
        if (c == '-')
            neg = 1, c = getChar();
        for (; isdigit(c); c = getChar())
            x = x * 10 + c - '0';
        if (neg)
            x = -x;
    }
    void read(long long &x) {
        x = 0;
        bool neg = 0;
        char c;
        while (isSpace(c = getChar()))
            ;
        if (c == '-')
            neg = 1, c = getChar();
        for (; isdigit(c); c = getChar())
            x = x * 10 + c - '0';
        if (neg)
            x = -x;
    }
    void read(double &x) {
        x = 0, cur = "";
        bool neg = 0;
        char c;
        while (isSpace(c = getChar()))
            ;
        if (c == '-')
            neg = 1, c = getChar();
        for (; isdigit(c); c = getChar())
            cur += c;
        if (c == '.')
            c = getChar();
        for (; isdigit(c); c = getChar())
            cur += c;
        if (neg)
            x = -x;
        x = stod(cur);
    }
    void read(std::string &x) {
        x = "";
        char c;
        while (isSpace(c = getChar()))
            ;
        for (;!isSpace(c); c = getChar())
            x += c;
    }
} scan;

int main() {
    int t;
    scan.read(t);
    while (t--) {
        int n;
        scan.read(n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scan.read(arr[i]);
        }
        int prevWinner = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                if (prevWinner == 0) {
                    prevWinner = 2;
                }
            }
            if (prevWinner == 2 || prevWinner == 0) {
                if ((arr[i] - 1) % 2 == 0) {
                    cout << 2 << endl;
                    prevWinner = 2;
                } else {
                    cout << 1 << endl;
                    prevWinner = 1;
                }
            } else {
                if ((arr[i] - 1) % 2 == 0) {
                    cout << 1 << endl;
                    prevWinner = 1;
                } else {
                    cout << 2 << endl;
                    prevWinner = 2;
                }
            }
        }
    }
    return 0;
}

