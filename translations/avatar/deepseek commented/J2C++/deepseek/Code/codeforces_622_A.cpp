#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <deque>
#include <cstdio>
#include <cstring>

using namespace std;

#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
#define PB push_back
#define PF push_front
#define MP make_pair
#define MT make_tuple
#define PI acos(-1)
#define F first
#define S second
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define IFOR(i, a, b) for(int i = (a); i >= (b); --i)
#define ALL(x) (x).begin(), (x).end()
#define D(x) cerr << #x << " = " << x << endl

const int BUFFERSIZE = 512000;

// Step 2: Define the Scanner and PrintWriter for input and output operations.
class Scanner {
public:
    Scanner(istream& is) : is(is) {
        buf.reserve(BUFFERSIZE);
    }

    string next() {
        while (!tokenizer.hasMoreTokens()) {
            getline(is, buf);
            tokenizer.str(buf);
        }
        return tokenizer.nextToken();
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
    istream& is;
    string buf;
    stringstream tokenizer;
};

class PrintWriter {
public:
    PrintWriter(ostream& os) : os(os) {}

    void print(const string& s) {
        os << s;
    }

    void println(const string& s) {
        os << s << endl;
    }

    void close() {
        os.flush();
    }

private:
    ostream& os;
};

// Step 3: Implement the solve method to find the position of a given value in a sequence.
void solve(Scanner& sc, PrintWriter& out) {
    long long position = sc.nextLong();
    long long nrstSeqStartIndx = 1;

    // Step 4: Find the starting index of the sequence where the position might be located.
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }

    // Step 4: Find the exact position within the sequence.
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }

    long long startIndex = getValueAtIndex(nrstSeqStartIndx);
    out.println((position - startIndex) + 1);
}

// Step 4: Implement the getValueAtIndex method to calculate the value at a specific index in the sequence.
long long getValueAtIndex(long long index) {
    return 1 + ((index - 1) * index / 2);
}

// Step 5: Implement the main method to initialize the input and call the solve method.
int main() {
    Scanner sc(cin);
    PrintWriter out(cout);
    solve(sc, out);
    out.close();
    return 0;
}
