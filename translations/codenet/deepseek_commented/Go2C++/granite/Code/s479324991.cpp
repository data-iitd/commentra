
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<float> arr(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = static_cast<float>(x);
    }

    sort(arr.begin(), arr.end());

    float prev = arr[0];
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }

    cout << prev << endl;

    return 0;
}

