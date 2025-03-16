#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int max(int a, int b) {
    return a < b ? b : a;
}

class Scanner {
public:
    Scanner(istream& is) : is(is) {}

    string Next() {
        string result;
        is >> result;
        return result;
    }

    int NextInt() {
        int v;
        is >> v;
        return v;
    }

    long long NextInt64() {
        long long v;
        is >> v;
        return v;
    }

    double NextFloat() {
        double v;
        is >> v;
        return v;
    }

    vector<int> NextIntArray() {
        vector<int> result;
        string line;
        getline(is, line);
        stringstream ss(line);
        int v;
        while (ss >> v) {
            result.push_back(v);
        }
        return result;
    }

private:
    istream& is;
};

int main() {
    Scanner sc(cin);
    int A = sc.NextInt();
    int B = sc.NextInt();

    int mx = max(A + B, A - B);
    mx = max(mx, A * B);
    cout << mx << endl;

    return 0;
}
