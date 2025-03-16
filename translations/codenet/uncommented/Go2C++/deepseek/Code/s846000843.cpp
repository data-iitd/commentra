#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <sstream>
#include <queue>
#include <map>
#include <fstream>

using namespace std;

struct Io {
    istream *reader;
    ostream *writer;
    vector<string> tokens;
    int nextToken;

    Io() : reader(&cin), writer(&cout), nextToken(0) {}

    void Flush() {
        writer->flush();
    }

    string NextLine() {
        string buffer;
        getline(*reader, buffer);
        return buffer;
    }

    string Next() {
        while (nextToken >= tokens.size()) {
            string line = NextLine();
            stringstream ss(line);
            tokens.clear();
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
            nextToken = 0;
        }
        return tokens[nextToken++];
    }

    int Int() {
        return stoi(Next());
    }

    double Float() {
        return stod(Next());
    }

    void PrintLn(const vector<int>& a) {
        for (int x : a) {
            cout << x << " ";
        }
        cout << endl;
    }

    void PrintLn(const vector<string>& a) {
        for (const string& x : a) {
            cout << x << " ";
        }
        cout << endl;
    }
};

Io io;

int Abs(int a) {
    return a >= 0 ? a : -a;
}

int Pow(int p, int q) {
    return static_cast<int>(pow(p, q));
}

int Min(const vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("funciton min() requires at least one argument.");
    }
    int res = nums[0];
    for (int num : nums) {
        res = min(res, num);
    }
    return res;
}

int Max(const vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("funciton max() requires at least one argument.");
    }
    int res = nums[0];
    for (int num : nums) {
        res = max(res, num);
    }
    return res;
}

vector<int> SortAsc(vector<int> a) {
    sort(a.begin(), a.end());
    return a;
}

vector<int> SortDesc(vector<int> a) {
    sort(a.begin(), a.end(), greater<int>());
    return a;
}

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    if (a == 0 && b == 0) {
        return 0;
    }
    return a * b / GCD(a, b);
}

vector<int> CumSum(const vector<int>& nums) {
    vector<int> sums = {0};
    for (int num : nums) {
        sums.push_back(sums.back() + num);
    }
    return sums;
}

int main() {
    io.reader = &cin;
    io.writer = &cout;

    int n = io.Int();
    vector<int> aa(n);
    for (int i = 0; i < n; i++) {
        aa[i] = io.Int();
    }

    vector<int> cumsum = CumSum(aa);

    int ans = 2020202020;
    for (int i = 1; i < cumsum.size() - 1; i++) {
        ans = min(ans, Abs(cumsum[cumsum.size() - 1] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    cout << ans << endl;

    return 0;
}
