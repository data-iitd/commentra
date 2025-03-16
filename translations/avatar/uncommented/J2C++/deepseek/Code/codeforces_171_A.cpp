#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class FastReader {
    istream* in;
    stringstream ss;
    string line;

public:
    FastReader() : in(&cin) {}

    string next() {
        while (!ss.good() && getline(*in, line)) {
            ss.str(line);
            ss.clear();
        }
        string ret;
        ss >> ret;
        return ret;
    }

    int nextInt() {
        return stoi(next());
    }

    long nextLong() {
        return stol(next());
    }

    double nextDouble() {
        return stod(next());
    }

    string nextLine() {
        string ret;
        getline(*in, ret);
        return ret;
    }
};

int reverse(int n) {
    if (n < 10) return n * 10;
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
