#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <memory>
#include <ctime>

using namespace std;

class FastScanner {
public:
    FastScanner() : buffer(nullptr), pos(0), end(0) {}

    void init(istream& input) {
        buffer = new char[BUFFER_SIZE];
        end = input.read(buffer, BUFFER_SIZE).gcount();
        pos = 0;
    }

    void close() {
        delete[] buffer;
        buffer = nullptr;
    }

    string next() {
        while (pos >= end || buffer[pos] <= ' ') {
            pos = 0;
            end = input.read(buffer, BUFFER_SIZE).gcount();
            if (end == 0) return "";
        }
        string token;
        while (pos < end && buffer[pos] > ' ') {
            token += buffer[pos++];
        }
        return token;
    }

    string nextLine() {
        string line;
        while (pos >= end || buffer[pos] <= ' ') {
            pos = 0;
            end = input.read(buffer, BUFFER_SIZE).gcount();
            if (end == 0) return "";
        }
        while (pos < end && buffer[pos] > ' ') {
            line += buffer[pos++];
        }
        return line;
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    double nextDouble() {
        return stod(next());
    }

private:
    static const int BUFFER_SIZE = 1024;
    char* buffer;
    int pos, end;
    istream& input;
};

int main() {
    FastScanner in;
    in.init(cin);
    int n = in.nextInt();

    int maxSum = 0;

    while (n-- > 0) {
        int f = in.nextInt();
        int t = in.nextInt();

        if (maxSum < f + t) {
            maxSum = f + t;
        }
    }

    cout << maxSum << endl;

    in.close();
    return 0;
}

