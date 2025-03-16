#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> A = {a, b, c, d};
    if (b <= c || d <= a) {
        cout << 0 << endl;
    } else {
        sort(A.begin(), A.end());
        cout << A[2] - A[1] << endl;
    }
    return 0;
}

