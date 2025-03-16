#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int nextInt() {
    int i;
    cin >> i;
    return i;
}

int main() {
    int n = nextInt();
    vector<int> ar(3 * n);
    for (int i = 0; i < 3 * n; ++i) {
        ar[i] = nextInt();
    }
    sort(ar.begin(), ar.end());
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += ar[3 * n - (i + 1) * 2];
    }
    cout << sum << endl;
    return 0;
}
