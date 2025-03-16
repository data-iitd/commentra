// by syu
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

// Define a custom Scanner class to read input efficiently.
class Scanner {
public:
    Scanner(istream& in = cin) : in(in) {
        in.sync_with_stdio(false);
        in.tie(0);
    }

    int nextInt() {
        int n;
        in >> n;
        return n;
    }

    long long nextLong() {
        long long n;
        in >> n;
        return n;
    }

    double nextDouble() {
        double n;
        in >> n;
        return n;
    }

    string next() {
        string n;
        in >> n;
        return n;
    }

    string nextLine() {
        string n;
        getline(in, n);
        return n;
    }

    template<typename T>
    void read(T& n) {
        in >> n;
    }

private:
    istream& in;
};

// Define a custom Print class to print output efficiently.
class Print {
public:
    Print(ostream& out = cout) : out(out) {
        out.sync_with_stdio(false);
        out.tie(0);
    }

    void print(int n) {
        out << n;
    }

    void print(long long n) {
        out << n;
    }

    void print(double n) {
        out << n;
    }

    void print(string n) {
        out << n;
    }

    template<typename T>
    void print(T& n) {
        out << n;
    }

private:
    ostream& out;
};

// Define a custom input function to read input efficiently.
template<typename T>
T read() {
    T n;
    cin >> n;
    return n;
}

// Define a custom print function to print output efficiently.
template<typename T>
void print(T& n) {
    cout << n;
}

// Define a custom println function to print output efficiently.
template<typename T>
void println(T& n) {
    cout << n << endl;
}

// Define a custom println function to print output efficiently.
void println() {
    cout << endl;
}

// Define a custom println function to print output efficiently.
void println(string s) {
    cout << s << endl;
}

// Define a custom println function to print output efficiently.
void println(int n) {
    cout << n << endl;
}

// Define a custom println function to print output efficiently.
void println(long long n) {
    cout << n << endl;
}

// Define a custom println function to print output efficiently.
void println(double n) {
    cout << n << endl;
}

// Define a custom println function to print output efficiently.
void println(char n) {
    cout << n << endl;
}

// Define a custom println function to print output efficiently.
void println(bool n) {
    cout << n << endl;
}

// Define a custom println function to print output efficiently.
void println(char* n) {
    cout << n << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n) {
    cout << n << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n) {
    cout << n << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, int m) {
    cout << n << m << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, int m) {
    cout << n << m << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m) {
    cout << n << m << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const char* m) {
    cout << n << m << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const string& m) {
    cout << n << m << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const char* m) {
    cout << n << m << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const char* m, const char* o) {
    cout << n << m << o << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const string& o) {
    cout << n << m << o << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const char* o) {
    cout << n << m << o << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const char* m, const string& o) {
    cout << n << m << o << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const char* m, const char* o) {
    cout << n << m << o << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const string& m, const string& o) {
    cout << n << m << o << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const string& m, const char* o) {
    cout << n << m << o << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const char* m, const string& o) {
    cout << n << m << o << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const char* m, const char* o, const char* p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const string& o, const string& p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const string& o, const char* p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const char* o, const string& p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const char* o, const char* p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const char* m, const string& o, const string& p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const char* m, const string& o, const char* p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const char* m, const char* o, const string& p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const char* m, const char* o, const char* p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const string& m, const string& o, const string& p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const string& m, const string& o, const char* p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const string& m, const char* o, const string& p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const string& m, const char* o, const char* p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const char* m, const string& o, const string& p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const char* m, const string& o, const char* p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const char* m, const char* o, const string& p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const char* n, const char* m, const char* o, const char* p) {
    cout << n << m << o << p << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const string& o, const string& p, const string& q) {
    cout << n << m << o << p << q << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const string& o, const string& p, const char* q) {
    cout << n << m << o << p << q << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const string& o, const char* p, const string& q) {
    cout << n << m << o << p << q << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const string& o, const char* p, const char* q) {
    cout << n << m << o << p << q << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const char* o, const string& p, const string& q) {
    cout << n << m << o << p << q << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const char* o, const string& p, const char* q) {
    cout << n << m << o << p << q << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const char* o, const char* p, const string& q) {
    cout << n << m << o << p << q << endl;
}

// Define a custom println function to print output efficiently.
void println(const string& n, const string& m, const char* o, const char* p, const char* q) {
    cout << n << m << o << p << q << endl;
}

// Def