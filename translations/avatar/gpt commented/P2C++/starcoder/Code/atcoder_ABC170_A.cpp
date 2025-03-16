#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int e = 0; e < n; e++) {
        if (a[e] == 0) {
            cout << e + 1 << endl;
            break;
        }
    }
    return 0;
}

