#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> ar(a);
    for (int i = 0; i < a; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < a; i++) {
        int max = 0, min;
        max = max(ar[i] - ar[0], ar[a - 1] - ar[i]);
        if (i == 0) {
            min = ar[i + 1] - ar[i];
        } else if (i == a - 1) {
            min = ar[i] - ar[i - 1];
        } else {
            min = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]);
        }
        cout << min << " " << max << endl;
    }
    return 0;
}
