
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int ma = max(A, max(B, C));
    int rest = A + B + C - ma - min(A, min(B, C));

    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }

    cout << ma + rest << endl;

    return 0;
}
