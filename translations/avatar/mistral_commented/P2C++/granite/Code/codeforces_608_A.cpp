
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    int c = 0;
    for (int i = 0; i < n; i++) {
        int f, t;
        cin >> f >> t;
        int x = t - (s - f);
        c = max(c, x);
    }

    cout << s + c << endl;
}

