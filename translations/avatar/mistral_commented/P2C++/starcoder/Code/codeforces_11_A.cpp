#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    int m = 0, q = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n-1; i++) {
        if (x[i] >= x[i+1]) {
            q = (x[i] - x[i+1]) / d + 1;
            m += q;
            x[i+1] += q * d;
        }
    }
    cout << m << endl;
    return 0;
}
