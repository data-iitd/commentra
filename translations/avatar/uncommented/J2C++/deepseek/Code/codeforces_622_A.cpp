#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

const int BUFFERSIZE = 512000;

class Scanner {
private:
    ifstream in;
    stringstream ss;
    string token;

public:
    Scanner(const string& filename) {
        in.open(filename);
        if (!in) {
            cerr << "Cannot open the file: " << filename << endl;
            exit(1);
        }
    }

    Scanner(istream& is) : in(std::cin.rdbuf()) {
        in.rdbuf(is.rdbuf());
    }

    ~Scanner() {
        in.close();
    }

    string next() {
        while (!ss.eof() && !ss.good()) {
            ss.clear();
            getline(in, token);
            ss.str(token);
        }
        if (ss.eof()) return "";
        string res;
        ss >> res;
        return res;
    }

    int nextInt() {
        return stoi(next());
    }

    double nextDouble() {
        return stod(next());
    }

    long long nextLong() {
        return stoll(next());
    }
};

class PrintWriter {
private:
    ostream& out;
    stringstream buffer;

public:
    PrintWriter(ostream& os) : out(os) {}

    void print(const string& s) {
        buffer << s;
    }

    void println(const string& s) {
        buffer << s << endl;
    }

    void close() {
        out << buffer.str();
    }
};

long long getValueAtIndex(long long index) {
    return 1 + (index - 1) * index / 2;
}

void solve(Scanner& sc, PrintWriter& out) {
    long long position = sc.nextLong();
    long long nrstSeqStartIndx = 1;
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }
    long long startIndex = getValueAtIndex(nrstSeqStartIndx);
    out.println(to_string(position - startIndex + 1));
}

int main() {
    Scanner sc(cin);
    PrintWriter out(cout);
    solve(sc, out);
    out.close();
    return 0;
}
