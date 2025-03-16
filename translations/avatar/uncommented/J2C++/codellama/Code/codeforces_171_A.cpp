
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

class FastReader {
    private:
        char buffer[100000];
        int ptr;
        int bufsize;
    public:
        FastReader() {
            ptr = 0;
            bufsize = 0;
        }
        char nextChar() {
            if (ptr == bufsize) {
                ptr = 0;
                bufsize = fread(buffer, sizeof(char), 100000, stdin);
            }
            return buffer[ptr++];
        }
        int nextInt() {
            int num = 0;
            char c = nextChar();
            while (c < '0') {
                c = nextChar();
            }
            while (c >= '0') {
                num = num * 10 + c - '0';
                c = nextChar();
            }
            return num;
        }
        long long nextLong() {
            long long num = 0;
            char c = nextChar();
            while (c < '0') {
                c = nextChar();
            }
            while (c >= '0') {
                num = num * 10 + c - '0';
                c = nextChar();
            }
            return num;
        }
        double nextDouble() {
            double num = 0;
            char c = nextChar();
            while (c < '0') {
                c = nextChar();
            }
            while (c >= '0') {
                num = num * 10 + c - '0';
                c = nextChar();
            }
            return num;
        }
        string nextLine() {
            string str = "";
            char c = nextChar();
            while (c != '\n') {
                str += c;
                c = nextChar();
            }
            return str;
        }
};

int reverse(int n) {
    if (n < 10) {
        return n * 10;
    }
    int t = n, r = 0;
    while (t > 0) {
        r = (r * 10) + t % 10;
        t = t / 10;
    }
    return r;
}

int main() {
    FastReader sc;
    int n = sc.nextInt();
    int m = sc.nextInt();
    int t = reverse(m);
    cout << t + n << endl;
    return 0;
}

