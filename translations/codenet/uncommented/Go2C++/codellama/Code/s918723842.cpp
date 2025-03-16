
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Scanner {
public:
    Scanner() {
        r = new istream(cin.rdbuf());
    }

    string Next() {
        string result;
        *r >> result;
        return result;
    }

    string NextLine() {
        string result;
        getline(*r, result);
        return result;
    }

    int NextInt() {
        int result;
        *r >> result;
        return result;
    }

    int64_t NextInt64() {
        int64_t result;
        *r >> result;
        return result;
    }

    double NextFloat() {
        double result;
        *r >> result;
        return result;
    }

    vector<int> NextIntArray() {
        vector<int> result;
        stringstream ss(Next());
        int tmp;
        while (ss >> tmp) {
            result.push_back(tmp);
        }
        return result;
    }

    vector<int64_t> NextInt64Array() {
        vector<int64_t> result;
        stringstream ss(Next());
        int64_t tmp;
        while (ss >> tmp) {
            result.push_back(tmp);
        }
        return result;
    }

    map<int, bool> NextMap() {
        map<int, bool> result;
        stringstream ss(Next());
        int tmp;
        while (ss >> tmp) {
            result[tmp] = true;
        }
        return result;
    }

private:
    istream *r;
};

int main() {
    Scanner sc;
    int H = sc.NextInt();
    int W = sc.NextInt();
    int N = sc.NextInt();

    int A = max(H, W);

    cout << (N + A - 1) / A << endl;

    return 0;
}

int max(int a, int b) {
    if (a < b) {
        return b;
    }
    return a;
}

