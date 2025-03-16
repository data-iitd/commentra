#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int64_t m = 0;
    for (int c = 1; c < n - 1; c++) {
        int f = 0;
        vector<bool> u(n, false);
        for (int k = 0; c < n - 1 - k * c; k++) {
            u[k * c] = true;
            if (u[n - 1 - k * c]) break;
            f += s[n - 1 - k * c] + s[k * c];
            if (m < f) m = f;
        }
        for (int k = 0; k * c < n - 1; k++) u[k * c] = false;
    }
    cout << m << endl;
    return 0;
}
