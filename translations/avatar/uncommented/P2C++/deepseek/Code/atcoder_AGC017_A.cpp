#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double combi(int N, int K) {
    double a = 1.0;
    for (int i = 0; i < K; ++i) {
        a *= (N - i);
    }
    for (int j = 0; j < K; ++j) {
        a /= (j + 1);
    }
    return a;
}

int main() {
    int N, P;
    cin >> N >> P;
    vector<int> lis;
    vector<int> ls;
    int a;
    while (cin >> a) {
        lis.push_back(a);
    }
    for (int i = 0; i < lis.size(); ++i) {
        ls.push_back(lis[i] % 2);
    }
    int one = 0, zero = 0;
    for (int i = 0; i < ls.size(); ++i) {
        if (ls[i] == 1) {
            ++one;
        } else {
            ++zero;
        }
    }
    double pattern_a = 0.0, pattern_b = 0.0;
    for (int j = 0; j <= zero; ++j) {
        pattern_b += combi(zero, j);
    }
    int time = 0;
    while (time <= one) {
        if (time % 2 == P) {
            pattern_a += combi(one, time);
        }
        ++time;
    }
    cout << static_cast<int>(pattern_a * pattern_b) << endl;
    return 0;
}

