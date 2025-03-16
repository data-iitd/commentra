// by syu
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

// Define a custom scanner type that wraps istream
class Scanner {
public:
    Scanner(istream& is) : is(is) {}
    Scanner(const string& s) : is(stringstream(s)) {}

    Scanner& operator>>(int& n) {
        string s;
        is >> s;
        n = stoi(s);
        return *this;
    }

    Scanner& operator>>(string& s) {
        getline(is, s);
        return *this;
    }

private:
    istream& is;
};

// Define a custom printer type that wraps ostream
class Printer {
public:
    Printer(ostream& os) : os(os) {}

    template <typename T>
    Printer& operator<<(const T& t) {
        os << t;
        return *this;
    }

private:
    ostream& os;
};

// Define a custom printer type that wraps ostream
class Pln {
public:
    Pln(ostream& os) : os(os) {}

    template <typename T>
    void operator<<(const T& t) {
        os << t << endl;
    }

private:
    ostream& os;
};

// Define a custom scanner instance for reading from standard input
Scanner in(cin);

// Define a custom printer instance for writing to standard output
Pln out(cout);

// Entry point of the program
int main() {
    // Read two integers n and k from standard input
    int n, k;
    in >> n >> k;
    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0 to the console
        out << 0;
    } else {
        // If n is not divisible by k, print 1 to the console
        out << 1;
    }
    return 0;
}

