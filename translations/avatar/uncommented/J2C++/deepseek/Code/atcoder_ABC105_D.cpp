#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

class TaskD {
public:
    void solve(int testNumber, InputReader& in, PrintWriter& out) {
        int n = in.nextInt();
        int m = in.nextInt();
        vector<int> a(n);
        unordered_map<int, int> dp;
        long long ans = 0;
        int base = 0;
        for (int i = 0; i < n; i++) {
            base = (base - a[i] % m + m) % m;
            dp[(base + a[i]) % m]++;
            ans += dp[base];
        }
        out.println(ans);
    }
};

class InputReader {
private:
    istream& in;

public:
    InputReader(istream& inputStream) : in(inputStream) {
    }

    int nextInt() {
        int number;
        in >> number;
        return number;
    }

    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            in >> res[i];
        }
        return res;
    }
};

class PrintWriter {
private:
    ostream& out;

public:
    PrintWriter(ostream& outputStream) : out(outputStream) {
    }

    void println(const long long& value) {
        out << value << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InputReader in(cin);
    PrintWriter out(cout);
    TaskD solver;
    solver.solve(1, in, out);

    return 0;
}

