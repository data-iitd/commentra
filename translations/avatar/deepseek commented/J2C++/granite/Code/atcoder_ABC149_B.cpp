
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <numeric>
#include <bitset>
#include <cassert>
#include <random>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

class Main {
public:
    long long A, B, K;
    long long x, y;

    Main(const vector<string>& args) {
        A = stoll(args[0]);
        B = stoll(args[1]);
        K = stoll(args[2]);
    }

    void calc() {
        x = A;
        y = B;
        x = A - K; // Subtract K from A to get the new value of x
        if (x < 0) {
            y = B + x; // Adjust B by the negative value of x
            x = 0; // Set x to 0 if it becomes negative
            if (y < 0) {
                y = 0; // Set y to 0 if it becomes negative
            }
        }
    }

    void showResult() {
        cout << x << " " << y << endl; // Print the final values of x and y
    }
};

int main(int argc, char *argv[]) {
    vector<string> args;
    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }
    Main ins(args);
    ins.calc();
    ins.showResult();
    return 0;
}

