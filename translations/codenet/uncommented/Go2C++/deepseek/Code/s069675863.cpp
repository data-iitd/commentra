#include <bits/stdc++.h>
using namespace std;

#define DEBUG
#ifdef DEBUG
#define PrintDebug(...) printDebug(__LINE__, __FUNCTION__, __VA_ARGS__)
#else
#define PrintDebug(...)
#endif

void printDebug(int line, const char* func, const char* format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, "L%d (%s) : ", line, func);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    va_end(args);
}

#define MOD         1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64   (1LL << 60)
#define INF_BIT60   1LL << 60
#define INF_INT32   (1 << 30)
#define INF_BIT30   1 << 30
#define NIL         -1

#define WHITE 0
#define GRAY  1
#define BLACK 2

string ReadString() {
    string s;
    cin >> s;
    return s;
}

int ReadInt() {
    return stoi(ReadString());
}

vector<int> ReadIntSlice(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

vector<int64_t> ReadInt64Slice(int n) {
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

double ReadFloat64() {
    return stod(ReadString());
}

vector<double> ReadFloat64Slice(int n) {
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

vector<char> ReadRuneSlice() {
    string s;
    cin >> s;
    vector<char> a(s.size());
    for (int i = 0; i < s.size(); i++) {
        a[i] = s[i];
    }
    return a;
}

vector<string> ReadStringSlice(int n) {
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

void PrintIntsLine(const vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i != A.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void PrintInts64Line(const vector<int64_t>& A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i != A.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void PrintfDebug(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    va_end(args);
}

void PrintfBufStdout(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

vector<string> Split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

