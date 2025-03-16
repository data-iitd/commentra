#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

const long long INF = numeric_limits<long long>::max();
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

class Scanner {
public:
    Scanner(istream& is) : is(is) {}

    string next() {
        string line;
        getline(is, line);
        return line;
    }

    int nextInt() {
        int num;
        is >> num;
        return num;
    }

    vector<int> nextInts(int n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            is >> nums[i];
        }
        return nums;
    }

    long long nextLong() {
        long long num;
        is >> num;
        return num;
    }

    double nextDouble() {
        double num;
        is >> num;
        return num;
    }

private:
    istream& is;
};

Scanner newScanner() {
    return Scanner(cin);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Scanner scanner = newScanner();
    string N = scanner.next();
    vector<char> b(N.begin(), N.end());
    int n = 0;

    for (char c : b) {
        n += c - '0';
    }

    int m = stoi(N);
    if (m % n == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
