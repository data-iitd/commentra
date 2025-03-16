
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    int ma = max(A, B, C);
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }
    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }
    cout << ma + rest << endl;
    return 0;
}

